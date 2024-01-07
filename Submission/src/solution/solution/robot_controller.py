# Based on: https://github.com/ros-planning/navigation2/blob/humble/nav2_simple_commander/nav2_simple_commander/example_nav_to_pose.py

import sys
import argparse
import math
import random

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.duration import Duration

from geometry_msgs.msg import PoseStamped, Point, Twist, Pose
from assessment_interfaces.msg import ItemHolders, ItemHolder, Item, ItemList
from nav_msgs.msg import Odometry
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult

from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

from tf_transformations import euler_from_quaternion, quaternion_from_euler
import angles

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

        self.state = State.SET_GOAL
        self.robot_holding = False

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.pose = Pose()
        self.x = 0
        self.y = 0
        self.distance = 0
        self.angle = 0.0
        
        self.items = ItemList()

        self.current_goal = Point()
        self.current_goal_type = 'Search'
        self.goal_item = Item()
        self.goal_distance = 0
        self.goal_value = 0
        self.holding_value = 0

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
        self.navigator.setInitialPose(initial_pose)
        self.navigator.waitUntilNav2Active()

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.item_holder_subscriber = self.create_subscription(
            ItemHolders,
            '/item_holders',
            self.item_holder_callback,
            10
        )

        self.odom_subscriber = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10
        )

        self.item_subscriber = self.create_subscription(
            msg_type=ItemList,
            topic='items',
            callback=self.item_callback,
            qos_profile=10,
            )

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        
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
                self.holding_value = itemHolder.item_value
                return

    def odom_callback(self, msg):
        self.pose = msg.pose.pose # Store the pose in a class variable

        (roll, pitch, yaw) = euler_from_quaternion([self.pose.orientation.x,
                                                    self.pose.orientation.y,
                                                    self.pose.orientation.z,
                                                    self.pose.orientation.w])
        
        self.yaw = yaw # Store the yaw in a class variable

    def item_callback(self, msg):
        self.items = msg

    ##################
    ## Control Loop ##
    ##################

    def control_loop(self):

        if self.robot_holding:
            better_item_found = self.assess_items(self.holding_value)
        else:
            better_item_found = self.assess_items(self.goal_value)

        self.get_logger().info(f"Has robot found item: {better_item_found}")

        if better_item_found:
            self.navigator.cancelTask()
            self.get_logger().info(f"Higher valued Item found - Moving...")
            self.current_goal_type = 'Collect'

            self.angle = self.goal_item.x / 320.0
            goalPoint = Point()
            goalPoint.x = self.pose.position.x + self.goal_distance * math.cos(self.angle)
            goalPoint.y = self.pose.position.y + self.goal_distance * math.sin(self.angle)
            
            self.current_goal = goalPoint
            self.state = State.SET_GOAL

        time_difference = self.get_clock().now() - self.previous_time

        if time_difference > Duration(seconds = 30):
            self.navigator.cancelTask()
            self.previous_time = self.get_clock().now()
            self.get_logger().info(f"Homing...")
            self.current_goal_type = 'Home'
            self.state = State.HOMING

        self.get_logger().info(f"State: {self.state}")

        match self.state:

            case State.SET_GOAL:

                if self.current_goal_type == 'Search':
                    self.current_goal, self.angle = self.randomise_pose()
                
                goal_pose = PoseStamped()
                goal_pose.header.frame_id = 'map'
                goal_pose.header.stamp = self.get_clock().now().to_msg()                
                goal_pose.pose.position = self.current_goal

                (goal_pose.pose.orientation.x,
                 goal_pose.pose.orientation.y,
                 goal_pose.pose.orientation.z,
                 goal_pose.pose.orientation.w) = quaternion_from_euler(0, 0, math.radians(self.angle), axes='sxyz')
                                
                self.get_logger().info(f"Navigating to: ({goal_pose.pose.position.x:.2f}, {goal_pose.pose.position.y:.2f}), {self.angle:.2f} degrees")

                self.navigator.goToPose(goal_pose)
                self.state = State.NAVIGATING

            case State.NAVIGATING:

                if not self.navigator.isTaskComplete():

                    feedback = self.navigator.getFeedback()
                    self.get_logger().info(f"Estimated time of arrival: {(Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9):.0f} seconds")

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
                            self.current_goal_type = 'Search'
                            self.state = State.SET_GOAL

                        case TaskResult.FAILED:
                            self.get_logger().info(f"Goal failed!")
                            self.current_goal_type = 'Search'
                            self.state = State.SET_GOAL

                        case _:
                            self.get_logger().info(f"Goal has an invalid return status!")

            case State.BACKUP:

                if not self.navigator.isTaskComplete():

                    feedback = self.navigator.getFeedback()
                    self.get_logger().info(f"Distance travelled: {feedback.distance_traveled:.2f} metres")

                else:

                    result = self.navigator.getResult()

                    match result:

                        case TaskResult.SUCCEEDED:
                            self.get_logger().info(f"Goal succeeded!")
                            if self.current_goal_type == 'Collect':
                                self.state = State.HOMING
                                self.current_goal_type = 'Home'
                            else:
                                self.state = State.SET_GOAL

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

            case State.HOMING:

                #Change self.distance to be distance home or smth. 
                if self.distance < 0.1:
                    self.navigator.spin(spin_dist=math.radians(180), time_allowance=10)
                    self.previous_time = self.get_clock().now()
                    self.get_logger().info(f"Made it home!")
                    self.current_goal_type = 'Search'
                    self.state = State.SPINNING
                    return
                
                try:
                    x = self.pose.position.x - self.home_pose.position.x
                    y = self.pose.position.y - self.home_pose.position.y

                    distance = math.sqrt(x ** 2 + y ** 2)
                    angle = math.atan2(y, x)

                    self.get_logger().info(f"x: {x:.2f}")
                    self.get_logger().info(f"y: {y:.2f}")
                    self.get_logger().info(f"distance: {distance:.2f}")
                    self.get_logger().info(f"angle (degrees): {math.degrees(angle):.2f}")

                    msg = Twist()

                    if math.fabs(angle) > math.radians(15):
                        msg.linear.x = 0.0
                    else:
                        msg.linear.x = 0.3 * distance
                        
                    msg.angular.z = 0.5 * angle

                    self.cmd_vel_publisher.publish(msg)

                except TransformException as e:
                    self.get_logger().info(f"{e}")

            case _:
                pass

    def randomise_pose(self):
        # Extracting the initial position values
        x = self.pose.position.x
        y = self.pose.position.y

        # Generating a random angle in radians
        random_angle = random.uniform(0, 2 * 3.14159)
        random_distance = random.uniform(0.5, 1.0)

        # Calculating the new position on the robot's radius of between 0.5 and 1.0
        new_x = x + random_distance * math.cos(random_angle)
        new_y = y + random_distance * math.sin(random_angle)

        # Creating a new Pose message with the randomized position
        randomised_point = Point()
        randomised_point.x = new_x
        randomised_point.y = new_y

        return randomised_point, random_angle

    def assess_items(self, value_to_compare, goal_distance_threshold = 1, item_distance_threshold = 1.5):
        better_item_found = False
        distance_to_item = 0

        self.get_logger().info(f"Empty list? {self.items.data}")
        item_test = Item()
        item_test = self.items.data[0].item
        self.get_logger().info(f"First item: {item_test}")

        for item in self.items.data:
            distance_to_item = 69.0 * float(item.diameter) ** -0.89

            if self.goal_item.item != None:
                if distance_to_item < self.goal_distance or (self.goal_distance > goal_distance_threshold and distance_to_item < item_distance_threshold):
                    # Assess if the item is better and closer
                    if item.value > value_to_compare:
                        self.goal_item = item
                        self.goal_value = item.value
                        self.goal_distance = distance_to_item
                        better_item_found = True
                
            else:
                self.goal_item = item
                self.goal_value = item.value
                self.goal_distance = distance_to_item
                better_item_found = True

        return better_item_found

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