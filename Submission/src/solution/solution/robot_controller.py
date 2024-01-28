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
    """
    Enumeration of the different states of the robot controller.

    This Enum class defines various states that the robot can be in during its operation. 
    These states are used to control the flow of the robot's decision-making process 
    and actions in the environment.

    Attributes:
        CHECK_ITEMS:       
            The state in which the robot checks for the presence of items.
            It is the initial state where the robot assesses its surroundings for items.
        FIND_NEAREST_ITEM: 
            The state where the robot identifies and locates the nearest item.
            In this state, the robot calculates the position of the closest item for retrieval.
        SET_HOME:          
            The state for setting the robot's home location, to then navigate towards.
        SET_SEARCH: 
            The state where the robot sets a random goal for navigation.
        NAVIGATING: 
            The state in which the robot is actively navigating towards a goal.
            This state is active when the robot is moving towards an item, returning to the home base or naviagating randomly.
    """

    CHECK_ITEMS = 0
    FIND_NEAREST_ITEM = 1
    SET_HOME = 2
    SET_SEARCH = 3
    NAVIGATING = 4

class RobotController(Node):

    def __init__(self):
        """
        Initialize the robot controller node.

        This method sets up various parameters, variables, ROS services, subscribers, 
        and a control loop timer necessary for the operation of the robot.
        """
        # Initialize the ROS node
        super().__init__('robot_controller')

        ####################################
        ## Initialise Parameter Arguments ##
        ####################################

        # Declare and initialize ROS parameters
        self.declare_parameter('initial_pose', rclpy.Parameter.Type.DOUBLE_ARRAY)
        self.declare_parameter('robot_name', rclpy.Parameter.Type.STRING)

        # Retrieve initial pose and robot name from parameters
        init_pose = self.get_parameter('initial_pose').value
        self.robot_name = self.get_parameter('robot_name').value

        # Log the robot name and initial pose for verification
        self.get_logger().info(f"Robot name: {self.robot_name}")
        self.get_logger().info(f"Initial Pose: {init_pose}")

        ##########################
        ## Initialise variables ##
        ##########################

        # Initialize state and basic variables
        self.state = State.CHECK_ITEMS
        self.robot_holding = False
        self.item_value = 0

        # Set initial pose based on parameters
        self.pose = Pose()
        self.pose.position.x = init_pose[0]
        self.pose.position.y = init_pose[1]
        self.yaw = 0.0

        # Initialise point variables for random navigation and home point navigation
        self.home_point = Point()
        self.random_goal = Point()
        self.random_goal_angle = 0.0

        #############################
        ## Initialise Initial Pose ##
        #############################

        # Set up the initial pose for navigation
        initial_pose = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = self.get_clock().now().to_msg()
        initial_pose.pose.position.x = init_pose[0]
        initial_pose.pose.position.y = init_pose[1]

        # Convert initial yaw to quaternion for ROS compatibility
        (initial_pose.pose.orientation.x,
         initial_pose.pose.orientation.y,
         initial_pose.pose.orientation.z,
         initial_pose.pose.orientation.w) = quaternion_from_euler(0, 0, math.radians(0), axes='sxyz')

        ###############################
        ## Initialise NAV2 Navigator ##
        ###############################

        # Initialize the navigator for path planning and navigation
        self.navigator = BasicNavigator()

        ####################################
        ## Initialise ROS Callback Groups ##
        ####################################

        # Create callback groups for organizing callbacks
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

        # Initialize ROS services for random goal setting and item assessment
        self.random_goal_client = self.create_client(RandomGoal, 'random_goal', callback_group=service_callback_group)
        self.item_assessment_client = self.create_client(ItemAssessment, 'item_assessor', callback_group=service_callback_group)

        # Wait for services to become available
        while not self.random_goal_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Random Service not available, waiting again...')
        while not self.item_assessment_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Item Service not available, waiting again...')

        # Initialize service requests
        self.random_goal_request = RandomGoal.Request()
        self.item_assessment_request = ItemAssessment.Request()

        ###########################
        ## Update Nav2 Navigator ##
        ###########################

        # Set the initial pose in the navigator and wait for Nav2 to become active
        self.navigator.setInitialPose(initial_pose)
        self.navigator.waitUntilNav2Active()

        ######################
        ## Initialise Timer ##
        ######################

        # Initialize the control loop timer with a frequency of 10 Hz
        self.timer_period = 0.1 # 100 milliseconds
        self.timer = self.create_timer(self.timer_period, self.control_loop, callback_group=timer_callback_group)

        # Store the current time for later use
        self.previous_time = self.get_clock().now()

    ############################
    ## Subscription Callbacks ##
    ############################
        
    def item_holder_callback(self, msg):
        """
        Callback function for processing item holder information.

        Args:
            msg: A ROS message that contains the current state of item holders. 
                This is expected to be of type ItemHolders, which is a list of ItemHolder objects.

        This function updates the robot's state based on whether it's currently holding an item.
        It iterates through each ItemHolder in the received message to check if the current robot 
        (identified by self.robot_name) is holding an item. If so, it updates the robot's state 
        accordingly, along with the value of the item being held.
        """
        # Reassign the received message to the itemHolders variable for clarity.
        itemHolders = msg 
        # Initialize an ItemHolder object. This will be used in the following loop.
        itemHolder = ItemHolder()
        # Iterate through each item holder in the received list.
        for itemHolder in itemHolders.data:
            # Check if the current robot is holding an item.
            if itemHolder.robot_id == self.robot_name and itemHolder.holding_item:
                # Update the robot's state to indicate it is holding an item.
                self.robot_holding = True
                # Store the value of the item being held.
                self.item_value = itemHolder.item_value
                # Exit the function as the relevant item holder is found.
                return
        # If the robot is not found in the list, or not holding an item, set robot_holding to False.
        self.robot_holding = False

    def item_callback(self, msg):
        """
        Callback function for processing received item information.

        Args:
            msg: A ROS message containing information about items. 
                This message is expected to be of a type that includes a list of Item objects.

        This function updates the list of items currently known to the robot.
        """
        # Update the robot's list of items with the received information.
        self.items = msg

    def robot_position_callback(self, msg):
        """
        Callback function for updating the robot's position.

        Args:
            msg: A ROS message containing the current position and orientation (yaw) of the robot.
                The message type is expected to provide these details.

        This function updates the robot's pose and yaw based on the received message. 
        This information is typically published by a 'robot_position_publisher.py' node.
        """
        # Update the robot's pose with the received positional information.
        self.pose = msg.pose
        # Update the robot's yaw (orientation) with the received value.
        self.yaw = msg.yaw

    ##################
    ## Control Loop ##
    ##################

    def control_loop(self):
        """
        Main control loop for the robot.

        This method is called periodically and handles different states of the robot's operation 
        based on the current state. It includes logic for checking items, finding the nearest item, 
        setting the home location, searching for items, and navigating to various points.
        """

        # Calculate the time elapsed since the last execution of this loop
        time_difference = self.get_clock().now() - self.previous_time

        # If more than 5 minutes (300 seconds) have passed, reset to home state
        if time_difference > Duration(seconds = 300):
            self.navigator.cancelTask()
            self.previous_time = self.get_clock().now()
            self.get_logger().info(f"Homing...")
            self.state = State.SET_HOME

        # Log the current state for debugging
        self.get_logger().info(f"State: {self.state}")

        # State machine handling different robot behaviors
        match self.state:

            case State.CHECK_ITEMS:
                # In this state, the robot checks if it is currently holding any item.
                if not self.robot_holding:
                    # If the robot is not holding an item, it checks if there are any items available.
                    if len(self.items.data) > 0:
                        # If there are items, it sends a request to the item assessment service 
                        # to determine the properties and values of the items.
                        self.item_assessment_request.items = self.items
                        self.item_assessment_request.value = self.item_value
                        self.item_assessment_response = self.item_assessment_client.call_async(self.item_assessment_request)
                        # After sending the request, the robot's state is set to find the nearest item.
                        self.state = State.FIND_NEAREST_ITEM
                    else:
                        # If there are no items, the robot requests a random goal to navigate to.
                        self.random_goal_request.x = self.pose.position.x
                        self.random_goal_request.y = self.pose.position.y
                        self.random_goal_response = self.random_goal_client.call_async(self.random_goal_request)
                        # The state is set to set search for a new goal.
                        self.state = State.SET_SEARCH
                else:
                    # If the robot is holding an item, it changes its state to set home 
                    # to return to the home base.
                    self.state = State.SET_HOME
                return

            case State.FIND_NEAREST_ITEM:
                # In this state, the robot waits for the item assessment response.
                if self.item_assessment_response.done():
                    try:
                        # Once the response is received, it processes the result.
                        response = self.item_assessment_response.result()
                        self.get_logger().info('Response received from Item Assessment Service')
                        # The robot updates its internal data with the details of the nearest item.
                        self.item = response.item
                        self.item_distance = response.distance
                        self.item_value = response.item.value
                    except Exception as e:
                        # If there's an error in the service call, it logs the error.
                        self.get_logger().info('Service call failed %r' % (e,))
                else:
                    # If the response is not yet ready, it exits the function to wait longer.
                    return
                
                # Calculating the angle relative to the robot to navigate towards the item.
                focal_length = 640 / (2 * math.tan(1.085595 / 2))
                angle_rel_robot = math.atan2((self.item.x), focal_length)
                angle = self.yaw + angle_rel_robot
                # Normalize the angle
                self.item_angle = (angle + math.pi) % (2 * math.pi) - math.pi

                # Calculate the goal point to navigate to based on the item's location.
                item_point = Point()
                item_point.x = self.pose.position.x + ((self.item_distance) * math.cos(self.item_angle))
                item_point.y = self.pose.position.y + ((self.item_distance) * math.sin(self.item_angle))

                # Setting up the goal pose for navigation.
                goal_pose = PoseStamped()
                goal_pose.header.frame_id = 'map'
                goal_pose.header.stamp = self.get_clock().now().to_msg()                
                goal_pose.pose.position = item_point
                # Convert the angle to quaternion for the pose.
                (goal_pose.pose.orientation.x,
                goal_pose.pose.orientation.y,
                goal_pose.pose.orientation.z,
                goal_pose.pose.orientation.w) = quaternion_from_euler(0, 0, self.item_angle, axes='sxyz')
                
                # Log the goal position and initiate navigation.
                self.get_logger().info(f"Navigating to: ({goal_pose.pose.position.x:.2f}, {goal_pose.pose.position.y:.2f}), {self.item_angle:.2f} degrees")
                self.navigator.goToPose(goal_pose)
                # Change the state to navigating towards the goal.
                self.state = State.NAVIGATING

            case State.SET_HOME:
                # In this state, the robot sets its home point.
                self.home_point.y = self.pose.position.y
                self.home_point.x = -3.5
                
                # Setting up the home pose for navigation.
                home_pose = PoseStamped()
                home_pose.header.frame_id = 'map'
                home_pose.header.stamp = self.get_clock().now().to_msg()                
                home_pose.pose.position = self.home_point
                # Setting a default orientation for the home pose.
                (home_pose.pose.orientation.x,
                home_pose.pose.orientation.y,
                home_pose.pose.orientation.z,
                home_pose.pose.orientation.w) = quaternion_from_euler(0, 0, math.radians(0), axes='sxyz')
                
                # Log the home position and initiate navigation.
                self.get_logger().info(f"Navigating to home: ({home_pose.pose.position.x:.2f}, {home_pose.pose.position.y:.2f})")
                self.navigator.goToPose(home_pose)
                # Change the state to navigating towards the home.
                self.state = State.NAVIGATING

            case State.SET_SEARCH:
                # In this state, the robot waits for a response from the random goal service.
                if self.random_goal_response.done():
                    try:
                        # Once the response is received, it processes the result.
                        response = self.random_goal_response.result()
                        self.get_logger().info('Response received from Random Goal Service')
                        # The robot updates its internal data with the details of the random goal.
                        self.random_goal.x = response.new_x
                        self.random_goal.y = response.new_y
                        self.random_goal_angle = response.angle
                    except Exception as e:
                        # If there's an error in the service call, it logs the error.
                        self.get_logger().info('Service call failed %r' % (e,))
                else:
                    # If the response is not yet ready, it exits the function to wait longer.
                    return

                # Setting up the search pose for navigation based on the random goal.
                search_pose = PoseStamped()
                search_pose.header.frame_id = 'map'
                search_pose.header.stamp = self.get_clock().now().to_msg()                
                search_pose.pose.position = self.random_goal
                # Convert the angle to quaternion for the pose.
                (search_pose.pose.orientation.x,
                search_pose.pose.orientation.y,
                search_pose.pose.orientation.z,
                search_pose.pose.orientation.w) = quaternion_from_euler(0, 0, self.random_goal_angle, axes='sxyz')

                # Log the search position and initiate navigation.
                self.get_logger().info(f"Navigating to: ({search_pose.pose.position.x:.2f}, {search_pose.pose.position.y:.2f}), {self.random_goal_angle:.2f} degrees")
                self.navigator.goToPose(search_pose)
                # Change the state to navigating towards the search goal.
                self.state = State.NAVIGATING

            case State.NAVIGATING:
                # In the navigating state, the robot checks if the navigation task is complete.
                if not self.navigator.isTaskComplete():
                    # Get feedback from the navigator for the estimated time of arrival.
                    feedback = self.navigator.getFeedback()
                    self.get_logger().info(f"Estimated time of arrival: {(Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9):.0f} seconds")

                    # Check if the navigation is taking too long and cancel if it exceeds 30 seconds.
                    if Duration.from_msg(feedback.navigation_time) > Duration(seconds=30):
                        self.get_logger().info("Navigation took too long... cancelling")
                        self.navigator.cancelTask()
                        # Decide the next state based on whether the robot is holding an item.
                        if self.robot_holding:
                            self.state = State.SET_HOME
                        else:
                            self.state = State.CHECK_ITEMS
                            self.item_value = 0
                else:
                    # Once the navigation task is complete, process the result.
                    result = self.navigator.getResult()

                    # Handle different navigation outcomes such as success, cancellation, or failure.
                    match result:
                        case TaskResult.SUCCEEDED:
                            self.get_logger().info("Goal succeeded!")
                            # Decide the next state based on whether the robot is holding an item.
                            if self.robot_holding:
                                self.state = State.SET_HOME
                            else:
                                self.state = State.CHECK_ITEMS
                                self.item_value = 0
                        case TaskResult.CANCELED:
                            self.get_logger().info("Goal was canceled!")
                            self.state = State.CHECK_ITEMS
                            self.item_value = 0
                        case TaskResult.FAILED:
                            self.get_logger().info("Goal failed!")
                            self.state = State.CHECK_ITEMS
                            self.item_value = 0
                        case _:
                            self.get_logger().info("Goal has an invalid return status!")

            # Handle any other undefined states.
            case _:
                pass

    def destroy_node(self):
        # Gracefully shut down the node.
        self.get_logger().info("Shutting down")
        self.navigator.lifecycleShutdown()
        self.navigator.destroyNode()
        super().destroy_node()

def main(args=None):
    # Initialize ROS and the robot controller node.
    rclpy.init(args=args)
    node = RobotController()

    # Set up a multi-threaded executor for handling callbacks.
    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        # Spin the executor to process callbacks.
        executor.spin()
    except KeyboardInterrupt:
        # Handle keyboard interrupt (Ctrl+C).
        pass
    except ExternalShutdownException:
        # Handle any external shutdown exceptions.
        sys.exit(1)
    finally:
        # Ensure proper shutdown of the executor and node.
        executor.shutdown()
        node.destroy_node()
        rclpy.try_shutdown()

if __name__ == '__main__':
    # Run the main function when the script is executed.
    main()