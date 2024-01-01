#############
## Imports ##
#############

import sys

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException

#IMPORT MSG SPECIFICS
from geometry_msgs.msg import Pose, PoseStamped
from std_msgs.msg import Header
from assessment_interfaces.msg import Item, ItemList
from solution_interfaces.msg import GoalStatus, GoHome

from enum import Enum
import random
import math

############
## States ##
############

class State(Enum):
    IDLE = 0
    SEARCH = 1
    ASSESS_AND_COLLECT_ITEM = 2
    GO_HOME = 3

##########
## Node ##
##########

class State_Manager(Node):

    ####################
    ## Initialisation ##
    ####################

    def __init__(self):

        ##########################
        ## Initialise variables ##
        ##########################

        self.state = State.IDLE
        self.goal_value = 0
        self.robot_spawned = True

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.item_subscriber = self.create_subscription(
            ItemList,
            '/items',
            self.item_callback,
            10
        )

        self.pose_subscriber = self.create_subscription(
            Pose,
            '/current_pose',
            self.pose_callback,
            10
        )

        self.goal_subscriber = self.create_subscription(
            GoalStatus,
            '/goal_status',
            self.pose_callback,
            10
        )

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.goal_pose_publisher = self.create_publisher(PoseStamped, '/goal_pose', 10)
        self.state_goHome_publisher = self.create_publisher(GoHome, '/goHome_trigger', 10)

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1
        self.timer = self.create_timer(self.timer_period, self.control_loop)
    
    ############################
    ## Subscription Callbacks ##
    ############################

    def pose_callback(self, msg):
        self.pose = msg

    def goal_callback(self, msg):
        self.goal_status = msg
    
    def item_callback(self, msg):
        if msg != []:
            self.items = msg
        else:
            self.items = None

    ##################
    ## Control Loop ##
    ##################

    def contol_loop(self):

        self.get_logger().info(f"State: {self.state}")

        match self.state:
            case State.IDLE:
                if self.is_robot_carrying():
                    self.previous_state = self.state
                    self.state = State.GO_HOME
                else:
                    if self.is_robot_home(): 
                        self.robot_spawned = False
                        self.previous_state = self.state
                        self.state = State.SEARCH
                        return
                    else:
                        self.state = self.previous_state
                        self.previous_state = State.IDLE

            case State.SEARCH:
                if self.items is not None:
                    self.previous_state = self.state
                    self.state = State.ASSESS_AND_COLLECT_ITEM
                    self.goal_pose_timer = 0

                else:
                    if self.goal_status == 'Completed':
                        goal_poseStamped = self.randomize_position()
                        self.goal_pose_publisher.publish(goal_poseStamped)
                        self.goal_pose_timer = 0

                    elif self.goal_status == 'Processing' and self.goal_pose_timer > 5:
                        goal_poseStamped = self.randomize_position()
                        self.goal_pose_publisher.publish(goal_poseStamped)
                        self.goal_pose_timer = 0

                    else:
                        self.goal_pose_time += 0.1

            case State.ASSESS_AND_COLLECT_ITEM:
                # Check if the robot is carrying items
                if self.goal_status != 'Completed':
                    if self.robot_is_carrying():
                        if self.goal_value <= self.holding_value:
                            best_item, distance_to_item = self.assess_items(self.holding_value, 0.5, 1)
                            
                            if best_item is not None:
                                # Set goal to the new item coordinates
                                self.prev_goal = self.goal_pose
                                self.goal_pose.pose.position.x = best_item.x
                                self.goal_pose.pose.position.y = best_item.y
                                self.goal_value = best_item.value
                                self.goal_distance = distance_to_item

                                self.send_goal_pose("Item_Goal")
                                return
                            else:
                                self.state = self.previous_state
                                self.previous_state = State.ASSESS_AND_COLLECT_ITEM
                        else:
                            self.send_goal_pose("Item_Goal")
                            return

                    else:
                        best_item, distance_to_item = self.assess_items(self.goal_value)
                            
                        if best_item is not None:
                            # Set goal to the new item coordinates
                            self.prev_goal = self.goal_pose
                            self.goal_pose.pose.position.x = best_item.x
                            self.goal_pose.pose.position.y = best_item.y
                            self.goal_value = best_item.value
                            self.goal_distance = distance_to_item

                            self.send_goal_pose("Item_Goal")
                            return

                        else:
                            return
                else:
                    self.previous_state = self.state
                    self.state = State.IDLE
                    return

            case State.GO_HOME:
                if self.goal_status != 'Home':
                    if self.items is not None:
                        self.previous_state = self.state
                        self.state = State.ASSESS_AND_COLLECT_ITEM

                        goHome_trigger = GoHome()
                        header = Header()
                        header.stamp = self.get_clock().now().to_msg()
                        header.frame_id = "Stop homing"
                        goHome_trigger.header = header
                        goHome_trigger.go_home_trigger = False

                        self.state_goHome_publisher.publish(goHome_trigger)
                        self.trigger_sent == False #Cancelled

                    else:
                        if self.trigger_sent == False:
                            goHome_trigger = GoHome()
                            header = Header()
                            header.stamp = self.get_clock().now().to_msg()
                            header.frame_id = "Start homing"
                            goHome_trigger.header = header
                            goHome_trigger.go_home_Trigger = True

                            self.state_goHome_publisher.publish(goHome_trigger)
                            self.trigger_sent == True
                    return
                else:
                    goHome_trigger = GoHome()
                    header = Header()
                    header.stamp = self.get_clock().now().to_msg()
                    header.frame_id = "Homing Completed"
                    goHome_trigger.header = header
                    goHome_trigger.go_home_Trigger = False

                    self.state_goHome_publisher.publish(goHome_trigger)
                    self.previous_state = self.state
                    self.state = State.IDLE

            case _:
                pass

    ################
    ## Procedures ##
    ################

    def assess_items(self, value_to_compare, goal_distance_threshold = 1, item_distance_threshold = 1.5):
        best_item = None
        distance_to_item = 0

        item = Item()
        for item in self.items:
            distance_to_item = math.sqrt((self.pose.position.x - item.x) ** 2 + (self.pose.position.y - item.y) ** 2)

            if distance_to_item < self.goal_distance or (self.goal_distance > goal_distance_threshold and distance_to_item < item_distance_threshold):
                # Assess if the item is better and closer
                if item.value > value_to_compare:
                    best_item = item

        return best_item, distance_to_item

    def is_robot_home(self):
        if self.goal_status == 'Home' or self.robot_spawned == True:
            return True
        else:
            return False

    def send_goal_pose(self, str_frame_id):
        header = Header()
        header.stamp = self.get_clock().now().to_msg()
        header.frame_id = str_frame_id

        msg = PoseStamped()
        msg.header = header
        msg.pose = self.goal_pose
        
        # Publish the goal_pose to /goal_pose for the robot controller
        self.goal_pose_publisher.publish(msg)

    def randomize_position(self):
        # Extracting the initial position values
        x = self.pose.position.x
        y = self.pose.position.y

        # Generating a random angle in radians
        random_angle = random.uniform(0, 2 * 3.14159)

        # Calculating the new position on the robot's radius of 1
        new_x = x + 1.0 * math.cos(random_angle)
        new_y = y + 1.0 * math.sin(random_angle)

        # Creating a new Pose message with the randomized position
        randomized_pose = Pose()
        randomized_pose.position.x = new_x
        randomized_pose.position.y = new_y
        randomized_pose.position.z = self.pose.position.z
        randomized_pose.orientation = self.pose.orientation  # Keeping the orientation unchanged

        header = Header()
        header.stamp = self.get_clock().now().to_msg()
        header.frame_id = "Random Goal"

        msg = PoseStamped()
        msg.header = header
        msg.pose = randomized_pose

        return msg       
    
    ##############
    ## Shutdown ##
    ##############

    def destroy_node(self):
        self.get_logger().info(f"Stopping Robot State Manager")
        super().destroy_node()

##########
## Main ##
##########

def main(args=None):

    rclpy.init(args = args, signal_handler_options = SignalHandlerOptions.NO)

    node = State_Manager()

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