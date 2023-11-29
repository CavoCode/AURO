import sys

import rclpy
from rclpy.node import Node

from solution_interfaces.msg import MachineState

#Finite State machine (FSM) states for the overall machine
class Machine_State(Enum):
    IDLE = 0
    EXPLORE = 1
    ASSESS_ITEM_ENVIRONMENT = 2
    COLLECT_ITEM = 3
    GO_HOME = 4
    ERROR_DETECTED = 5

class State_Manager(Node):

    def __init__(self):
        self.machine_state = Machine_State.IDLE

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.state_listener = self.create_subscription(
            MachineState,
            '/machine_state_request',
            self.state_callback,
            10
        )

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.state_publisher = self.create_publisher(MachineState, '/machine_state', 10)

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1
        self.timer = self.create_timer(self.timer_period, self.control_loop)
    
    def contol_loop(self):


        match self.machine_state:

            case Machine_State.IDLE:
                '''
                self.movement_state = Movement_State.Stationary

                if error_detected():
                    self.machine_state = Machine_State.ERROR_DETECTED

                if is_robot_available() && is_robot_home(): 
                    #DO CHECKS FOR IF MACHINE IS FACING WALL - TURN TO FACE OPEN MAP RATHER THAN HOME

                    #THEN SET MACHINE STATE TO EXPLORE
                    self.machine_state = Machine_State.EXPLORE
                else if is_robot_carrying():
                    #DO CHECK IF HIGHER VALUE TARGET IS IN SITE - If yes transition to ASSESS_ITEM_ENVIRONMENT
                    #else
                    self.machine_state = Machine_State.GO_HOME
                else:
                    self.machine_state = Machine_State.EXPLORE
                '''

            case Machine_State.EXPLORE:
                
                if 

            case Machine_State.ASSESS_ITEM_ENVIRONMENT:
                1 == 1
                #Assess if item is in within sight, else go to EXPLORE state
                #If item already collected, assess if higher value target is within sight and reasonable distance

                #If highest value item available and more items of same value very close
                #Update global location of last seen highest value target
                #So other robots can approach area

            case Machine_State.COLLECT_ITEM:
                1 == 1
                #After collection always move to assess_item_environment
                #to see if higher value target is within sight and reasonable distance

            case Machine_State.GO_HOME:
                1 == 1

            case Machine_State.ERROR_DETECTED:
                1 == 1

            case _:
                pass