#!/usr/bin/env python3

import sys
import math

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from rclpy.duration import Duration

from geometry_msgs.msg import PoseStamped, Point, Pose
from assessment_interfaces.msg import ItemHolders, ItemHolder, ItemList, Item
from solution_interfaces.msg import RobotPubPosition
from solution_interfaces.srv import RandomGoal, ItemAssessment
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult

from tf_transformations import quaternion_from_euler

from enum import Enum

class State(Enum):
    CHECK_ITEMS = 0
    FIND_NEAREST_ITEM = 1
    SET_HOME = 2
    SET_SEARCH = 3
    NAVIGATING = 4

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        ####################################
        ## Initialise Parameter Arguments ##
        ####################################

        self.declare_parameter('initial_pose', rclpy.Parameter.Type.DOUBLE_ARRAY)
        self.declare_parameter('robot_name', rclpy.Parameter.Type.STRING)

        init_pose = self.get_parameter('initial_pose').value
        self.robot_name = self.get_parameter('robot_name').value

        self.get_logger().info(f"Robot name: {self.robot_name}")
        self.get_logger().info(f"Initial Pose: {init_pose}")

        ##########################
        ## Initialise variables ##
        ##########################

        self.state = State.CHECK_ITEMS
        self.robot_holding = False
        self.item_value = 0

        self.pose = Pose()
        self.pose.position.x = init_pose[0]
        self.pose.position.y = init_pose[1]
        self.yaw = 0.0

        self.home_point = Point()
        self.random_goal = Point()
        self.random_goal_angle = 0.0

        #############################
        ## Initialise Initial Pose ##
        #############################

        initial_pose = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = self.get_clock().now().to_msg()
        initial_pose.pose.position.x = init_pose[0]
        initial_pose.pose.position.y = init_pose[1]

        (initial_pose.pose.orientation.x,
         initial_pose.pose.orientation.y,
         initial_pose.pose.orientation.z,
         initial_pose.pose.orientation.w) = quaternion_from_euler(0, 0, math.radians(0), axes='sxyz')

        ###############################
        ## Initialise NAV2 Navigator ##
        ###############################

        self.navigator = BasicNavigator()

        ###########################
        ## Update Nav2 Navigator ##
        ###########################

        self.navigator.setInitialPose(initial_pose)
        self.navigator.waitUntilNav2Active()

        ####################################
        ## Initialise ROS Callback Groups ##
        ####################################

        subscriber_callback_group = MutuallyExclusiveCallbackGroup()
        service_callback_group = MutuallyExclusiveCallbackGroup()
        timer_callback_group = MutuallyExclusiveCallbackGroup()

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.item_holder_subscriber = self.create_subscription(
            ItemHolders,
            '/item_holders',
            self.item_holder_callback,
            1,
            callback_group=subscriber_callback_group)

        self.item_subscriber = self.create_subscription(
            ItemList,
            'items',
            self.item_callback,
            10,
            callback_group=subscriber_callback_group)

        self.robot_position_subscriber = self.create_subscription(
            RobotPubPosition,
            'robot_position',
            self.robot_position_callback,
            1,
            callback_group=subscriber_callback_group)

        ##############################
        ## Initialise ROS Services ##
        ##############################

        self.random_goal_client = self.create_client(RandomGoal, 'random_goal', callback_group=service_callback_group)
        while not self.random_goal_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.random_goal_request = RandomGoal.Request()

        self.item_assessment_client = self.create_client(ItemAssessment, 'item_assessor', callback_group=service_callback_group)
        while not self.item_assessment_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.item_assessment_request = ItemAssessment.Request()

        ###########################
        ## Update Nav2 Navigator ##
        ###########################

        self.navigator.setInitialPose(initial_pose)
        self.navigator.waitUntilNav2Active()

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop, callback_group=timer_callback_group)

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
                self.item_value = itemHolder.item_value
                return
            
        self.robot_holding = False

    def item_callback(self, msg):
        self.items = msg

    def robot_position_callback(self, msg):
        self.pose = msg.pose
        self.yaw = msg.yaw
    
    ##################
    ## Control Loop ##
    ##################

    def control_loop(self):
        time_difference = self.get_clock().now() - self.previous_time

        if time_difference > Duration(seconds = 300):
            self.navigator.cancelTask()
            self.previous_time = self.get_clock().now()
            self.get_logger().info(f"Homing...")
            self.state = State.SET_HOME

        self.get_logger().info(f"State: {self.state}")

        match self.state:

            case State.CHECK_ITEMS:
                if len(self.items.data) > 0:
                    self.item_assessment_request.items = self.items
                    self.item_assessment_request.value = self.item_value
                    self.item_assessment_response = self.item_assessment_client.call_async(self.item_assessment_request)
                    self.state = State.FIND_NEAREST_ITEM
                else:
                    self.random_goal_request.x = self.pose.position.x
                    self.random_goal_request.y = self.pose.position.y
                    self.random_goal_response = self.random_goal_client.call_async(self.random_goal_request)
                    self.state = State.SET_SEARCH
                return

            case State.FIND_NEAREST_ITEM:
                if self.item_assessment_response.done():
                    try:
                        # Process the response
                        response = self.item_assessment_response.result()
                        self.get_logger().info('Response recieved from Item Assessment Service')
                        self.item = response.item
                        self.item_distance = response.distance
                        self.item_value = response.item.value

                    except Exception as e:
                        self.get_logger().info('Service call failed %r' % (e,))

                else:
                    return
                
                focal_length = 640 / (2 * math.tan(1.085595  / 2))
                angle_rel_robot = math.atan2((self.item.x), focal_length)
                angle = self.yaw + angle_rel_robot
                self.item_angle = (angle + math.pi) % (2 * math.pi) - math.pi  # Normalize

                item_point = Point()
                item_point.x = self.pose.position.x + ((self.item_distance) * math.cos(self.item_angle))
                item_point.y = self.pose.position.y + ((self.item_distance) * math.sin(self.item_angle))

                goal_pose = PoseStamped()
                goal_pose.header.frame_id = 'map'
                goal_pose.header.stamp = self.get_clock().now().to_msg()                
                goal_pose.pose.position = item_point

                (goal_pose.pose.orientation.x,
                goal_pose.pose.orientation.y,
                goal_pose.pose.orientation.z,
                goal_pose.pose.orientation.w) = quaternion_from_euler(0, 0, self.item_angle, axes='sxyz')
                                
                self.get_logger().info(f"Navigating to: ({goal_pose.pose.position.x:.2f}, {goal_pose.pose.position.y:.2f}), {self.item_angle:.2f} degrees")

                self.navigator.goToPose(goal_pose)
                self.state = State.NAVIGATING

            case State.SET_HOME:
                self.home_point.y = self.pose.position.y
                self.home_point.x = -3.5
                
                home_pose = PoseStamped()
                home_pose.header.frame_id = 'map'
                home_pose.header.stamp = self.get_clock().now().to_msg()                
                home_pose.pose.position = self.home_point

                (home_pose.pose.orientation.x,
                home_pose.pose.orientation.y,
                home_pose.pose.orientation.z,
                home_pose.pose.orientation.w) = quaternion_from_euler(0, 0, math.radians(0), axes='sxyz')
                                
                self.get_logger().info(f"Navigating to home: ({home_pose.pose.position.x:.2f}, {home_pose.pose.position.y:.2f})")

                self.navigator.goToPose(home_pose)
                self.state = State.NAVIGATING

            case State.SET_SEARCH:
                if self.random_goal_response.done():
                    try:
                        # Process the response
                        response = self.random_goal_response.result()
                        self.get_logger().info('Response recieved from Random Goal Service')
                        self.random_goal.x = response.new_x
                        self.random_goal.y = response.new_y
                        self.random_goal_angle = response.angle

                    except Exception as e:
                        self.get_logger().info('Service call failed %r' % (e,))

                else:
                    return

                search_pose = PoseStamped()
                search_pose.header.frame_id = 'map'
                search_pose.header.stamp = self.get_clock().now().to_msg()                
                search_pose.pose.position = self.random_goal

                (search_pose.pose.orientation.x,
                search_pose.pose.orientation.y,
                search_pose.pose.orientation.z,
                search_pose.pose.orientation.w) = quaternion_from_euler(0, 0, self.random_goal_angle, axes='sxyz')
                                
                self.get_logger().info(f"Navigating to: ({search_pose.pose.position.x:.2f}, {search_pose.pose.position.y:.2f}), {self.random_goal_angle:.2f} degrees")

                self.navigator.goToPose(search_pose)
                self.state = State.NAVIGATING

            case State.NAVIGATING:

                if not self.navigator.isTaskComplete():
                    
                    feedback = self.navigator.getFeedback()
                    self.get_logger().info(f"Estimated time of arrival: {(Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9):.0f} seconds")

                    if Duration.from_msg(feedback.navigation_time) > Duration(seconds = 30):
                        self.get_logger().info(f"Navigation took too long... cancelling")
                        self.navigator.cancelTask()
                        self.state = State.CHECK_ITEMS
                        self.item_value = 0

                else:
                    result = self.navigator.getResult()

                    match result:

                        case TaskResult.SUCCEEDED:
                            self.get_logger().info(f"Goal succeeded!")
                                
                            if self.robot_holding:
                                self.state = State.SET_HOME
                                return
                            else:
                                self.state = State.CHECK_ITEMS
                                self.item_value = 0

                        case TaskResult.CANCELED:
                            self.get_logger().info(f"Goal was canceled!")
                            self.state = State.CHECK_ITEMS
                            self.item_value = 0

                        case TaskResult.FAILED:
                            self.get_logger().info(f"Goal failed!")
                            self.state = State.CHECK_ITEMS
                            self.item_value = 0

                        case _:
                            self.get_logger().info(f"Goal has an invalid return status!")

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

    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()