import sys

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException
from rclpy.qos import QoSPresetProfiles

#IMPORT MSG SPECIFICS
from geometry_msgs.msg import Twist, Pose
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from auto_interfaces.msg import StringWithPose
from assessment_interfaces.msg import Item, ItemList

from tf_transformations import euler_from_quaternion
import angles

from enum import Enum
import random
import math

LINEAR_VELOCITY  = 0.3 # Metres per second
ANGULAR_VELOCITY = 0.5 # Radians per second

TURN_LEFT = 1 # Postive angular velocity turns left
TURN_RIGHT = -1 # Negative angular velocity turns right

SCAN_THRESHOLD = 0.5 # Metres per second
 # Array indexes for sensor sectors
SCAN_FRONT = 0
SCAN_LEFT = 1
SCAN_BACK = 2
SCAN_RIGHT = 3

#Finite State machine (FSM) states for the overall machine
class Machine_State(Enum):
    IDLE = 0
    EXPLORE = 1
    ASSESS_ITEM_ENVIRONMENT = 2
    COLLECT_ITEM = 3
    GO_HOME = 4
    ERROR_DETECTED = 5

#FSM states for movement
class Movement_State(Enum):
    FORWARD = 0
    TURNING = 1
    STATIONARY = 2

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        ##########################
        ## Initialise variables ##
        ##########################

        self.machine_state = Machine_State.IDLE #Machine State on start-up
        self.pose = Pose() #Current pose (position and orientation), relative to the odom reference frame
        self.previous_pose = Pose() #Store a snapshot of the pose for comparision against future poses
        self.yaw = 0.0
        self.previous_yaw = 0.0
        self.turn_angle = 0.0
        self.turn_direction = TURN_LEFT
        self.goal_distance = random.uniform(1.0,2.0)
        self.scan_triggered = [False] * 4
        self.items = ItemList()

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.item_subscriber = self.create_subscription(
            ItemList,
            '/items'
            self.item_callback,
            10)

        self.odom_subscriber = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10)
        
        self.scan_subscriber = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            QoSPresetProfiles.SENSOR_DATA.value)

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.marker_publisher = self.create_publisher(StringWithPose, '/marker_input', 10)

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1
        self.timer = self.create_timer(self.timer_period, self.control_loop)

    ############################
    ## Subscription Callbacks ##
    ############################

    def item_callback(self, msg):
        self.items = msg

    def odom_callback(self, msg):
        self.pose = msg.pose.pose # Store the pose in a class variable

        (roll, pitch, yaw) = euler_from_quaternion([self.pose.orientation.x,
                                                    self.pose.orientation.y,
                                                    self.pose.orientation.z,
                                                    self.pose.orientation.w])
        
        self.yaw = yaw # Store the yaw in a class variable

    def scan_callback(self, msg):
        # Group scan ranges into 4 segments
        # Front, left, and right segments are each 60 degrees
        # Back segment is 180 degrees
        front_ranges = msg.ranges[331:359] + msg.ranges[0:30] # 30 to 331 degrees (30 to -30 degrees)
        left_ranges  = msg.ranges[31:90] # 31 to 90 degrees (31 to 90 degrees)
        back_ranges  = msg.ranges[91:270] # 91 to 270 degrees (91 to -90 degrees)
        right_ranges = msg.ranges[271:330] # 271 to 330 degrees (-30 to -91 degrees)

        # Store True/False values for each sensor segment, based on whether the nearest detected obstacle is closer than SCAN_THRESHOLD
        self.scan_triggered[SCAN_FRONT] = min(front_ranges) < SCAN_THRESHOLD 
        self.scan_triggered[SCAN_LEFT]  = min(left_ranges)  < SCAN_THRESHOLD
        self.scan_triggered[SCAN_BACK]  = min(back_ranges)  < SCAN_THRESHOLD
        self.scan_triggered[SCAN_RIGHT] = min(right_ranges) < SCAN_THRESHOLD

    ##################
    ## Control Loop ##
    ##################

    # Control loop for the FSM - called periodically by self.timer
    def control_loop(self):

        # Send message to rviz_text_marker node
        marker_input = StringWithPose()
        marker_input.text = str(self.movement_state) # Visualise robot movement state as an RViz marker
        marker_input.pose = self.pose # Set the pose of the RViz marker to track the robot's pose
        self.marker_publisher.publish(marker_input)

        self.get_logger().info(f"Robot State: {self.machine_state}")
        self.get_logger().info(f"Movement State: {self.movement_state}")

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
                1 == 1

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

        match self.movement_state:

            case Movement_State.FORWARD:
                if self.scan_triggered[SCAN_FRONT]:
                    self.previous_yaw = self.yaw
                    self.state = State.TURNING
                    self.turn_angle = random.uniform(150, 170)
                    self.turn_direction = random.choice([TURN_LEFT, TURN_RIGHT])
                    self.get_logger().info("Detected obstacle in front, turning " + ("left" if self.turn_direction == TURN_LEFT else "right") + f" by {self.turn_angle:.2f} degrees")
                    return
                
                if self.scan_triggered[SCAN_LEFT] or self.scan_triggered[SCAN_RIGHT]:
                    self.previous_yaw = self.yaw
                    self.state = State.TURNING
                    self.turn_angle = random.uniform(45, 90)

                    if self.scan_triggered[SCAN_LEFT] and self.scan_triggered[SCAN_RIGHT]:
                        self.turn_direction = random.choice([TURN_LEFT, TURN_RIGHT])
                        self.get_logger().info("Detected obstacle to both the left and right, turning " + ("left" if self.turn_direction == TURN_LEFT else "right") + f" by {self.turn_angle:.2f} degrees")
                    elif self.scan_triggered[SCAN_LEFT]:
                        self.turn_direction = TURN_RIGHT
                        self.get_logger().info(f"Detected obstacle to the left, turning right by {self.turn_angle} degrees")
                    else: # self.scan_triggered[SCAN_RIGHT]
                        self.turn_direction = TURN_LEFT
                        self.get_logger().info(f"Detected obstacle to the right, turning left by {self.turn_angle} degrees")
                    return

                msg = Twist()
                msg.linear.x = LINEAR_VELOCITY
                self.cmd_vel_publisher.publish(msg)


            case Movement_State.TURNING:

                msg = Twist()
                msg.angular.z = self.turn_direction * ANGULAR_VELOCITY
                self.cmd_vel_publisher.publish(msg)

                yaw_difference = angles.normalize_angle(self.yaw - self.previous_yaw)

                if math.fabs(yaw_difference) >= math.radians(self.turn_angle):
                    self.goal_distance = random.uniform(1.0, 2.0)
                    self.state = State.FORWARD
                    self.get_logger().info(f"Finished turning, driving forward by {self.goal_distance:.2f} metres")


            case Movement_State.STATIONARY:
                1 == 1

            case _:
                pass


    def destroy_node(self):
        msg = Twist()
        self.cmd_vel_publisher.publish(msg)
        self.get_logger().info(f"Stopping: {msg}")
        super().destroy_node()


def main(args=None):

    rclpy.init(args = args, signal_handler_options = SignalHandlerOptions.NO)

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