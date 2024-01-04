#############
## Imports ##
#############

import sys

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException
from rclpy.qos import QoSPresetProfiles

#IMPORT MSG SPECIFICS
from geometry_msgs.msg import Pose, PoseStamped
from std_msgs.msg import Header
from assessment_interfaces.msg import Item, ItemList, HomeZone
from solution_interfaces.msg import GoalStatus, GoalPosition, LocateHome

from enum import Enum
import random
import math

############
## States ##
############

class State(Enum):
    STARTUP = 0
    SEARCH = 1
    ASSESS = 2
    COLLECT = 3
    CHECK_HOME = 4
    GO_HOME = 5

##########
## Node ##
##########

class State_Manager(Node):

    ####################
    ## Initialisation ##
    ####################

    def __init__(self):
        super().__init__('robot_state_manager')
        
        ##########################
        ## Initialise variables ##
        ##########################

        self.state = State.STARTUP
        self.status = 'IDLE'

        self.goal_item = Item()
        self.goal_value = 0
        self.goal_timer = 0

        self.items = ItemList()
        self.pose = Pose()

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.item_subscriber = self.create_subscription(
            msg_type=ItemList,
            topic='/items',
            callback=self.item_callback,
            qos_profile=10,
            callback_group=None)

        self.pose_subscriber = self.create_subscription(
            Pose,
            '/current_pose',
            self.pose_callback,
            10)

        self.goal_subscriber = self.create_subscription(
            GoalStatus,
            '/goal_status',
            self.pose_callback,
            10)

        self.homeZone_subscriber = self.create_subscription(
            HomeZone,
            '/HomeZone',
            self.homeZone_callback,
            10)


        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.goal_pose_publisher = self.create_publisher(GoalPosition, '/goal_pose', 10)
        self.locate_home_publisher = self.create_publisher(LocateHome, '/locate_home', 10)

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
        self.status = msg.status
        self.goal_type = msg.goal_type

    def homeZone_callback(self, msg):
        self.homeZone_visible = msg.visible

        if self.homeZone_visible == True:
            self.home_goal_pose = Pose()
            self.home_goal_pose.position.x = msg.x
            self.home_goal_pose.position.y = msg.y
            self.home_goal_size = msg.size
    
    def item_callback(self, msg):
        self.items = msg

    ##################
    ## Control Loop ##
    ##################

    def control_loop(self):

        self.get_logger().info(f"State: {self.state}")

        match self.state:
            case State.STARTUP:
                header = Header()
                header.stamp = self.get_clock().now().to_msg()
                header.frame_id = 'MOVE TO IDLE'

                locateHomeMsg = LocateHome()
                locateHomeMsg.header = header
                locateHomeMsg.locate_home = True

                self.locate_home_publisher.publish(locateHomeMsg)
                self.state = State.SEARCH

            case State.SEARCH:
                if len(self.items.data) > 0:
                    self.previous_state = self.state
                    self.state = State.ASSESS
                    self.goal_timer = 0

                else:
                    if self.status == 'IDLE':
                        self.send_pose("Search")
                        self.goal_timer = 0

                    elif self.status == 'Completed' and self.goal_type == 'Home':
                        self.send_pose("Search")
                        self.goal_timer = 0

                    elif self.status == 'Completed' and self.goal_type == 'Search':
                        self.send_pose("Search")
                        self.goal_timer = 0

                    elif self.status == 'Processing' and self.goal_type == 'Search' and self.goal_timer >= 5:
                        self.send_pose("Search")
                        self.goal_timer = 0

                    elif self.status == 'Processing' and self.goal_timer >= 10:
                        self.send_pose("Search")
                        self.goal_timer = 0

                    else:
                        self.goal_timer += 0.1
                
                return

            case State.ASSESS:
                # Check if the robot is carrying items
                if self.status != 'Completed' and self.goal_type == 'Collect':
                    better_item_found = self.assess_items(self.goal_value)
                    
                    if better_item_found:
                        self.state = State.COLLECT
                    else:
                        self.state = self.previous_state
                        self.previous_state = State.ASSESS

                        
                elif self.status != 'Completed' and self.goal_type == 'Home':
                    better_item_found = self.assess_items(self.holding_value)

                    if better_item_found:
                        self.state = State.COLLECT
                    else:
                        self.state = self.previous_state
                        self.previous_state = State.ASSESS

                else:
                    better_item_found = self.assess_items(0)
                    self.state = State.COLLECT


            case State.COLLECT:
                if len(self.items.data) > 0:
                    self.previous_state = self.state
                    self.state = State.ASSESS

                    self.goal_timer = 0
                
                if self.status != 'Processing' and self.previous_state == State.ASSESS:
                    if self.goal_item.x != self.goal_pose.pose.position.x and self.goal_item.y != self.goal_pose.pose.position.y: 
                        self.goal_pose.pose.position.x = self.goal_item.x
                        self.goal_pose.pose.position.y = self.goal_item.y
                        self.send_pose('Collect')

                    elif self.status == 'Completed' and self.goal_type == 'Collect':
                        self.state = State.CHECK_HOME
                    
                    else:
                        self.send_pose('Collect')
                else:
                    if self.goal_timer >= 5:
                        self.state = State.SEARCH
                        return

                    self.goal_timer += 0.1        
            

                return

            case State.CHECK_HOME:
                if self.homeZone_visible:
                    self.send_locateHome(True, 'Found Home')
                    self.state = State.GO_HOME
                else:
                    self.send_locateHome(False, 'Find Home')

                return

            case State.GO_HOME:
                if len(self.items.data) > 0:
                    self.previous_state = self.state
                    self.state = State.ASSESS
                    self.goal_pose_timer = 0

            case _:
                pass

    ################
    ## Procedures ##
    ################

    def assess_items(self, value_to_compare, goal_distance_threshold = 1, item_distance_threshold = 1.5):
        better_item_found = False
        distance_to_item = 0

        item = Item()
        for item in self.items.data:
            distance_to_item = math.sqrt((self.pose.position.x - item.x) ** 2 + (self.pose.position.y - item.y) ** 2)

            if self.best_item != None:
                if distance_to_item < self.goal_distance or (self.goal_distance > goal_distance_threshold and distance_to_item < item_distance_threshold):
                    # Assess if the item is better and closer
                    if item.value > value_to_compare:
                        self.prev_goal = self.goal_item
                        self.goal_item = item
                        self.goal_value = item.value
                        self.goal_distance = distance_to_item
                        better_item_found = True
                
            else:
                self.prev_goal = self.goal_item
                self.goal_item = item
                self.goal_value = item.value
                self.goal_distance = distance_to_item
                better_item_found = True

        return better_item_found

    def send_pose(self, goal_type):
        if goal_type == 'Search':
            poseStamped = self.randomize_position()
            
        elif goal_type == 'Collect':
            header = Header()
            header.stamp = self.get_clock().now().to_msg()
            header.frame_id = goal_type

            poseStamped = PoseStamped()
            poseStamped.header = header
            poseStamped.pose = self.goal_pose

        elif goal_type == 'Home':


        msg = GoalPosition()
        msg.poseStamped = poseStamped
        msg.goalType = goal_type

        # Publish the goal_pose to /goal_pose for the robot controller
        self.goal_pose_publisher.publish(msg)
        return

    def send_locateHome(self, locateHomeBool, frame_id):
        header = Header()
        header.stamp = self.get_clock().now().to_msg()
        header.frame_id = frame_id

        locateHomeMsg = LocateHome()
        locateHomeMsg.header = header
        locateHomeMsg.locate_home = locateHomeBool

        self.locate_home_publisher.publish(locateHomeMsg)

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