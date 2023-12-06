import sys

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException
from rclpy.qos import QoSPresetProfiles

#IMPORT MSG SPECIFICS
from geometry_msgs.msg import Pose
from nav_msgs.msg import Odometry
from assessment_interfaces.msg import Item, ItemList, HomeZone
from solution_interfaces.msg import MachineState

from enum import Enum
import random
import math


#Finite State machine (FSM) states for the overall machine
class State(Enum):
    IDLE = 0
    SEARCH = 1
    ASSESS_ITEM = 2
    COLLECT_ITEM = 3
    GO_HOME = 4
    ERROR_DETECTED = 5

class State_Manager(Node):

    def __init__(self):

        ##########################
        ## Initialise variables ##
        ##########################

        self.state = State.IDLE

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

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.state_publisher = self.create_publisher(MachineState, '/machine_state', 10)
        self.goal_pose_publisher = self.create_publisher(Pose, '/goal_pose', 10)

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1
        self.timer = self.create_timer(self.timer_period, self.control_loop)
    
    ############################
    ## Subscription Callbacks ##
    ############################

    def pose_callback(self, msg):
        self.current_pose = msg

    def item_callback(self, msg):
        self.items = msg

    ##################
    ## Control Loop ##
    ##################

    def contol_loop(self):
        match self.state:

            case State.IDLE:
                if self.error_detected:
                    self.state = State.ERROR_DETECTED

                elif self.is_robot_available() and self.is_robot_home(): 
                    self.state = State.SEARCH

                elif self.is_robot_carrying():
                    #DO CHECK IF HIGHER VALUE TARGET IS IN SITE - If yes transition to ASSESS_ITEM_ENVIRONMENT
                    #else
                    self.state = State.GO_HOME
                else:
                    self.state = State.SEARCH                

            case State.SEARCH:
                1==1


            case State.ASSESS_ITEM:
                for item in self.items:
                    if self.robot_is_carrying() and self.carried_value < item.value:
                        distance_to_item = math.sqrt((self.pose.x - item.x) ** 2 + (self.pose.y - item.y) ** 2)
                        #if item is in direction of home or within a certain distance
                            #set goal to item

                    elif item.value > self.goal_value:
                        distance_to_item = math.sqrt((self.pose.position.x - item.x) ** 2 + (self.pose.position.y - item.y) ** 2)
                        if distance_to_item < self.goal_distance:
                            self.prev_goal = self.goal_pose
                            self.goal_pose.pose.position.x  = item.x
                            self.goal_pose.pose.position.y = item.y
                            self.goal_value = item.value
                            self.goal_distance = distance_to_item
                            self.state = State.COLLECT_ITEM  

                        elif self.goal_distance > 1 and distance_to_item < 1.5:
                            self.prev_goal = self.goal_pose
                            self.goal_pose.pose.position.x  = item.x
                            self.goal_pose.pose.position.y  = item.y
                            self.goal_value = item.value
                            self.goal_distance = distance_to_item        
                            self.state = State.COLLECT_ITEM                                                  

                        elif self.goal_distance == 0: #Meaning no goal set
                            self.prev_goal = self.goal_pose
                            self.goal_pose.pose.position.x = item.x
                            self.goal_pose.pose.position.y = item.y
                            self.goal_value = item.value
                            self.goal_distance = distance_to_item
                            self.state = State.COLLECT_ITEM  

                    else:
                        self.state = State.GO_HOME  

            case State.COLLECT_ITEM:        
                if self.prev_goal != self.goal_pose:
                    if self.goal_status != 'Processing': 
                        if self.goal_status == 'Succeeded' and self.robot_is_carrying():
                            self.state = State.ASSESS_ITEM

                        elif self.goal_status == 'Cancelled' or (self.goal_status == 'Succeeded' and not self.is_robot_carrying()):
                            initialPoseStamped = self.set_initialPose()
                            goalPoseStamped = self.set_goalPose()
                            self.pose_publisher.publish(initialPoseStamped)
                            self.goal_publisher.publish(goalPoseStamped) 

                            self.prev_goal = self.goal_pose

                        elif self.goal_status == 'Failed' or self.goal_status == 'Invalid': 
                            self.error_description = 'Navigation is faulty, process failed or invalid!'
                            self.state = State.ERROR_DETECTED

            case State.GO_HOME:
                if 

            case State.ERROR_DETECTED:
                self.state = State.IDLE

                #LOG ERROR INFORMATION

            case _:
                pass
 
 def set_initialPose(self):
        initialPose = PoseStamped()
        initialPose.header.frame_id = 'map'
        initialPose.header.stamp = self.get_clock().now().to_msg()
        initialPose.pose.position.x = self.pose.position.x
        initialPose.pose.position.y = self.pose.position.y
        initialPose.pose.orientation.z = self.pose.orientation.z
        initialPose.pose.orientation.w = self.pose.orientation.w

        return initialPose
    
    def set_goalPose(self):
        goalPose = PoseStamped()
        goalPose.header.frame_id = 'map'
        goalPose.header.stamp = self.get_clock().now().to_msg()
        goalPose.pose.position.x = self.goal_pose.position.x
        goalPose.pose.position.y = self.goal_pose.position.y
        goalPose.pose.orientation.z = self.goal_pose.orientation.z
        goalPose.pose.orientation.w = 1.0

        return goalPose