import sys
import math

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from rclpy.duration import Duration

from geometry_msgs.msg import PoseStamped, Point, Twist, Pose
from assessment_interfaces.msg import ItemHolders, ItemHolder
from solution_interfaces.msg import ItemAssessment, RobotStart
from solution_interfaces.srv import RandomGoal
from nav_msgs.msg import Odometry
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult

from tf_transformations import euler_from_quaternion, quaternion_from_euler

from enum import Enum

class State(Enum):
    SET_GOAL = 0
    NAVIGATING = 1
    SPINNING = 2
    BACKUP = 3
    HOMING = 4

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        ####################################
        ## Initialise Parameter Arguments ##
        ####################################

        self.declare_parameter('initial_pose', rclpy.Parameter.Type.DOUBLE_ARRAY)
        self.declare_parameter('robot_name', rclpy.Parameter.Type.STRING)

        self.args_initial_pose = self.get_parameter('initial_pose').value
        self.robot_name = self.get_parameter('robot_name').value


        ##########################
        ## Initialise variables ##
        ##########################

        self.robot_started = RobotStart()
        self.robot_started.start_assessment = False

        self.state = State.SET_GOAL
        self.item_assessment = ItemAssessment()
        self.item_updated = False
        self.robot_holding = False

        self.pose = Pose()
        self.yaw = 0.0

        self.home_distance = 0
        self.home_angle = 0.0

        self.current_goal = Point()
        self.current_goal_type = 'Search'
        self.current_goal_angle = 0.0
        self.new_search = True

        #############################
        ## Initialise Initial Pose ##
        #############################

        initial_pose = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = self.get_clock().now().to_msg()
        initial_pose.pose.position.x = self.args_initial_pose[0]
        initial_pose.pose.position.y = self.args_initial_pose[1]

        (initial_pose.pose.orientation.x,
         initial_pose.pose.orientation.y,
         initial_pose.pose.orientation.z,
         initial_pose.pose.orientation.w) = quaternion_from_euler(0, 0, math.radians(0), axes='sxyz')

        self.home_pose = Pose()
        self.home_pose = initial_pose.pose

        self.get_logger().info(f"Robot name: {self.robot_name}")
        self.get_logger().info(f"Initial Pose: {self.args_initial_pose}")

        ###############################
        ## Initialise NAV2 Navigator ##
        ###############################

        self.navigator = BasicNavigator()

        ###########################
        ## Update Nav2 Navigator ##
        ###########################

        self.navigator.setInitialPose(initial_pose)
        self.navigator.waitUntilNav2Active()

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.item_assessor_subscriber = self.create_subscription(
            ItemAssessment,
            'item_assessor',
            self.item_assessor_callback,
            10
        )

        self.item_holder_subscriber = self.create_subscription(
            ItemHolders,
            '/item_holders',
            self.item_holder_callback,
            10
        )

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.robot_start_publisher = self.create_publisher(RobotStart, 'robot_start_trigger', 10)

        ##############################
        ## Initialise ROS Services ##
        ##############################

        random_client_callback_group = MutuallyExclusiveCallbackGroup()
        self.random_goal_client = self.create_client(RandomGoal, 'random_goal', callback_group=random_client_callback_group)
        while not self.random_goal_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.random_goal_request = RandomGoal.Request()

        ###########################
        ## Update Nav2 Navigator ##
        ###########################

        self.navigator.setInitialPose(initial_pose)
        self.navigator.waitUntilNav2Active()

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)

        self.previous_time = self.get_clock().now()

    ############################
    ## Subscription Callbacks ##
    ############################
        
    def item_holder_callback(self, msg):
        itemHolders = ItemHolders()
        itemHolders = msg

        itemHolder = ItemHolder()
        for itemHolder in itemHolders.data:
            if itemHolder.robot_id == self.robot_name and itemHolder.holding_item == True:
                self.robot_holding = True
                return
            
        self.robot_holding = False

    def item_assessor_callback(self, msg):
        # Define a small time window (in seconds) for matching timestamps
        time_window = 0.005  # Adjust as needed (5 milliseconds in this example)

        # Get the current clock time
        current_time = self.get_clock().now().to_msg()

        if msg.goal_point_stamped.header.stamp == current_time:
            self.item_assessment = msg
            self.get_logger().info(f"Updated with new item position from /item_assessor")
            self.current_goal = self.item_assessment.goal_point_stamped.point
            self.current_goal_type = self.item_assessment.goal_type
            self.item_updated = True

        else:
            self.item_updated = False
    
    ##################
    ## Control Loop ##
    ##################

    def control_loop(self):
        if self.robot_started.start_assessment == False:
            self.robot_started.start_assessment = True
            self.robot_start_publisher.publish(self.robot_started)

        time_difference = self.get_clock().now() - self.previous_time

        if time_difference > Duration(seconds = 300):
            self.navigator.cancelTask()
            self.previous_time = self.get_clock().now()
            self.get_logger().info(f"Homing...")
            self.current_goal_type = 'Home'
            self.state = State.HOMING

        if self.current_goal_type == 'Collect' and self.item_updated:
            self.item_updated = False
            self.navigator.cancelTask()
            self.state = State.SET_GOAL
        elif self.robot_holding and self.item_updated != True and self.state != State.NAVIGATING:
            self.navigator.cancelTask()
            self.state = State.HOMING

        if self.current_goal_type == 'Search' and self.state == State.SET_GOAL and self.new_search:
            self.random_goal_request.x = self.pose.position.x
            self.random_goal_request.y = self.pose.position.y

            self.random_goal_response = self.random_goal_client.call_async(self.random_goal_request)
            self.new_search = False

        self.get_logger().info(f"State: {self.state}")

        match self.state:

            case State.SET_GOAL:

                if self.current_goal_type == 'Search':
                    if self.random_goal_response.done():
                        try:
                            # Process the response
                            response = self.random_goal_response.result()
                            self.get_logger().info('Response recieved from Random Goal Service')
                            self.current_goal.x = response.new_x
                            self.current_goal.y = response.new_y
                            self.current_goal_angle = response.angle
                            self.new_search = True

                        except Exception as e:
                            self.get_logger().info('Service call failed %r' % (e,))
                    else:
                        return

                goal_pose = PoseStamped()
                goal_pose.header.frame_id = 'map'
                goal_pose.header.stamp = self.get_clock().now().to_msg()                
                goal_pose.pose.position = self.current_goal

                (goal_pose.pose.orientation.x,
                 goal_pose.pose.orientation.y,
                 goal_pose.pose.orientation.z,
                 goal_pose.pose.orientation.w) = quaternion_from_euler(0, 0, math.radians(self.current_goal_angle), axes='sxyz')
                                
                self.get_logger().info(f"Navigating to: ({goal_pose.pose.position.x:.2f}, {goal_pose.pose.position.y:.2f}), {self.current_goal_angle:.2f} degrees")

                self.navigator.goToPose(goal_pose)
                self.state = State.NAVIGATING

            case State.NAVIGATING:

                if not self.navigator.isTaskComplete():

                    feedback = self.navigator.getFeedback()
                    self.get_logger().info(f"Estimated time of arrival: {(Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9):.0f} seconds")
                    self.pose = feedback.current_pose.pose
                    self.get_logger().info(f"Estimated current pose: {self.pose}")

                    if Duration.from_msg(feedback.navigation_time) > Duration(seconds = 30):
                        self.get_logger().info(f"Navigation took too long... cancelling")
                        self.navigator.cancelTask()

                else:
                    result = self.navigator.getResult()

                    match result:

                        case TaskResult.SUCCEEDED:
                            self.get_logger().info(f"Goal succeeded!")
                            
                            self.get_logger().info(f"Spinning")

                            self.navigator.spin(spin_dist=math.radians(180), time_allowance=10)
                            self.state = State.SPINNING

                        case TaskResult.CANCELED:
                            self.get_logger().info(f"Goal was canceled!")
                            self.current_goal_type = 'Search'
                            self.state = State.SET_GOAL

                        case TaskResult.FAILED:
                            self.get_logger().info(f"Goal failed!")
                            self.current_goal_type = 'Search'
                            self.state = State.SET_GOAL

                        case _:
                            self.get_logger().info(f"Goal has an invalid return status!")

            case State.SPINNING:

                if not self.navigator.isTaskComplete():

                    feedback = self.navigator.getFeedback()
                    self.get_logger().info(f"Turned: {math.degrees(feedback.angular_distance_traveled):.2f} degrees")
                    self.pose = feedback.current_pose.pose

                else:

                    result = self.navigator.getResult()

                    match result:

                        case TaskResult.SUCCEEDED:
                            self.get_logger().info(f"Goal succeeded!")

                            self.get_logger().info(f"Backing up")

                            self.navigator.backup(backup_dist=0.15, backup_speed=0.025, time_allowance=10)
                            self.state = State.BACKUP

                        case TaskResult.CANCELED:
                            self.get_logger().info(f"Goal was canceled!")

                            self.state = State.SET_GOAL

                        case TaskResult.FAILED:
                            self.get_logger().info(f"Goal failed!")

                            self.state = State.SET_GOAL

                        case _:
                            self.get_logger().info(f"Goal has an invalid return status!")

            case State.BACKUP:

                if not self.navigator.isTaskComplete():

                    feedback = self.navigator.getFeedback()
                    self.get_logger().info(f"Distance travelled: {feedback.distance_traveled:.2f} metres")
                    self.pose = feedback.current_pose.pose

                else:

                    result = self.navigator.getResult()

                    match result:

                        case TaskResult.SUCCEEDED:
                            self.get_logger().info(f"Goal succeeded!")

                            self.state = State.SET_GOAL

                        case TaskResult.CANCELED:
                            self.get_logger().info(f"Goal was canceled!")

                            self.state = State.SET_GOAL

                        case TaskResult.FAILED:
                            self.get_logger().info(f"Goal failed!")

                            self.state = State.SET_GOAL

                        case _:
                            self.get_logger().info(f"Goal has an invalid return status!")

            case State.HOMING:

                #Change self.distance to be distance home or smth. 
                if self.home_distance < 0.1:
                    self.current_goal_type = 'Search'
                    self.navigator.spin(spin_dist=math.radians(180), time_allowance=10)
                    self.previous_time = self.get_clock().now()
                    self.get_logger().info(f"Made it home!")
                    self.state = State.SPINNING
                    return
                
                else:
                    x = self.pose.position.x - self.home_pose.position.x
                    y = self.pose.position.y - self.home_pose.position.y

                    self.home_distance = math.sqrt(x ** 2 + y ** 2)
                    self.home_angle = math.atan2(y, x)

                    self.get_logger().info(f"x: {x:.2f}")
                    self.get_logger().info(f"y: {y:.2f}")
                    self.get_logger().info(f"distance: {self.home_distance:.2f}")
                    self.get_logger().info(f"angle (degrees): {math.degrees(self.home_angle):.2f}")

                    msg = Twist()

                    if math.fabs(self.home_angle) > math.radians(15):
                        msg.linear.x = 0.0
                    else:
                        msg.linear.x = 0.3 * self.home_distance
                        
                    msg.angular.z = 0.5 * self.home_angle

                    self.cmd_vel_publisher.publish(msg)

            case _:
                pass

    def destroy_node(self):
        self.get_logger().info(f"Shutting down")
        self.navigator.lifecycleShutdown()
        self.navigator.destroyNode()
        super().destroy_node()
        

def main(args=None):

    rclpy.init(args = args)
    node = RobotController()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()