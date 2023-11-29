import sys

import rclpy
from rclpy.node import Node
from rclpy.signals import SignalHandlerOptions
from rclpy.executors import ExternalShutdownException
from rclpy.qos import QoSPresetProfiles

#IMPORT MSG SPECIFICS
from geometry_msgs.msg import Twist, Pose, PoseStamped
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from auto_interfaces.msg import StringWithPose
from assessment_interfaces.msg import Item, ItemList, HomeZone
from solution_interfaces.msg import MachineState, Goal

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
    BUILD_MAP = 1
    EXPLORE = 2
    ASSESS_ITEM_ENVIRONMENT = 3
    COLLECT_ITEM = 4
    GO_HOME = 5
    ERROR_DETECTED = 6

#Finite State machine (FSM) states for movement
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

        self.machine_state = Machine_State.IDLE
        self.movement_state = Movement_State.STATIONARY
        self.pose = Pose() #Current pose (position and orientation), relative to the odom reference frame
        self.previous_pose = Pose() #Store a snapshot of the pose for comparision against future poses
        self.yaw = 0.0
        self.previous_yaw = 0.0
        self.turn_angle = 0.0
        self.turn_direction = TURN_LEFT

        self.goal_pose = PoseStamped()
        self.goal_pose.header.frame_id = 'map'
        self.goal_pose.header.stamp = self.get_clock().now().to_msg()

        self.poseStamped = PoseStamped()
        self.poseStamped.header.frame_id = 'map'
        self.poseStamped.header.stamp = self.get_clock().now().to_msg()
        self.poseStamped.pose.position.x = self.pose.position.x
        self.poseStamped.pose.position.y = self.pose.position.y
        self.poseStamped.pose.orientation.z = self.pose.orientation.z
        self.poseStamped.pose.orientation.w = self.pose.orientation.w

        self.scan_triggered = [False] * 4
        self.items = ItemList()

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.goal_subscriber = self.create_subscription(
            Goal,
            '/goal_status',
            self.goal_status_callback,
            10)

        self.home_subscriber = self.create_subscription(
            HomeZone,
            '/home_zone',
            self.home_zone_callback,
            10)

        self.item_subscriber = self.create_subscription(
            ItemList,
            '/items',
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
        self.pose_publisher = self.create_publisher(PoseStamped, '/pose_pub', 10)
        self.goal_publisher = self.create_publisher(PoseStamped, '/goal_pos', 10)

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1
        self.timer = self.create_timer(self.timer_period, self.control_loop)

    ############################
    ## Subscription Callbacks ##
    ############################

    def goal_status_callback(self, msg):
        self.goal_status = msg

    def home_zone_callback(self, msg):
        self.home_zone = msg

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
                self.movement_state = Movement_State.Stationary

                if self.error_detected:
                    self.machine_state = Machine_State.ERROR_DETECTED

                #elif if file map does not exist
                    #self.machine_state = Machine_State.BUILD_MAP

                elif is_robot_available() and is_robot_home(): 
                    #DO CHECKS FOR IF MACHINE IS FACING WALL - TURN TO FACE OPEN MAP RATHER THAN HOME

                    #THEN SET MACHINE STATE TO EXPLORE
                    self.machine_state = Machine_State.EXPLORE
                elif is_robot_carrying():
                    #DO CHECK IF HIGHER VALUE TARGET IS IN SITE - If yes transition to ASSESS_ITEM_ENVIRONMENT
                    #else
                    self.machine_state = Machine_State.GO_HOME
                else:
                    self.machine_state = Machine_State.EXPLORE

            case Machine_State.BUILD_MAP:


            case Machine_State.EXPLORE:
                if self.items !=  []:
                    self.movement_state = Movement_State.STATIONARY
                    self.machine_state = Machine_State.ASSESS_ITEM_ENVIRONMENT
                else:
                    #EXPLORE
                    1==1

            case Machine_State.ASSESS_ITEM_ENVIRONMENT:
                for item in self.items:
                    if robot_is_carrying() and self.carried_value < item.value:
                        distance_to_item = math.sqrt((self.pose.x - item.x) ** 2 + (self.pose.y - item.y) ** 2)

                    elif item.value > self.goal_value:
                        distance_to_item = math.sqrt((self.pose.position.x - item.x) ** 2 + (self.pose.position.y - item.y) ** 2)
                        if distance_to_item < self.goal_distance:
                            self.goal_pose.pose.position.x  = item.x
                            self.goal_pose.pose.position.y = item.y
                            self.goal_value = item.value
                            self.goal_distance = distance_to_item
                        elif self.goal_distance > 1 and distance_to_item < 1.5:
                            self.goal_pose.pose.position.x  = item.x
                            self.goal_pose.pose.position.y  = item.y
                            self.goal_value = item.value
                            self.goal_distance = distance_to_item                            
                        elif self.goal_distance == 0: #Meaning no goal set
                            self.goal_pose.pose.position.x = item.x
                            self.goal_pose.pose.position.y = item.y
                            self.goal_value = item.value
                            self.goal_distance = distance_to_item

                self.machine_state = Machine_State.COLLECT_ITEM    

            case Machine_State.COLLECT_ITEM:        
                if self.items != []:
                    self.machine_state = Machine_State.ASSESS_ITEM_ENVIRONMENT
                else:
                    if self.goal_status != 'Processing':
                        self.poseStamped.
                        self.pose_publisher.publish(self.poseStamped)

                        self.goal_pose.pose.orientation.w = 1.0
                        self.goal_publisher.publish(self.goal_pose)   
                    elif self.goal_status == 'Succeeded' and robot_is_carrying():
                        self.machine_state = Machine_State.ASSESS_ITEM_ENVIRONMENT
                    
                        

                    #After collection always move to assess_item_environment
                    #to see if higher value target is within sight and reasonable distance

            case Machine_State.GO_HOME:
                1 == 1

            case Machine_State.ERROR_DETECTED:
                self.machine_state = Machine_State.IDLE
                self.movement_state = Movement_State.STATIONARY

                #LOG ERROR INFORMATION

            case _:
                pass

        match self.movement_state:

            case Movement_State.FORWARD:
                if self.scan_triggered[SCAN_FRONT]:
                    self.previous_yaw = self.yaw
                    self.state = Movement_State.TURNING
                    self.turn_angle = random.uniform(150, 170)
                    self.turn_direction = random.choice([TURN_LEFT, TURN_RIGHT])
                    self.get_logger().info("Detected obstacle in front, turning " + ("left" if self.turn_direction == TURN_LEFT else "right") + f" by {self.turn_angle:.2f} degrees")
                    return
                
                if self.scan_triggered[SCAN_LEFT] or self.scan_triggered[SCAN_RIGHT]:
                    self.previous_yaw = self.yaw
                    self.state = Movement_State.TURNING
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
                msg.linear.x = LINEAR_VELOCITY * self.goal_distance
                msg.angular.z = self.goal_x / 320.0
                self.cmd_vel_publisher.publish(msg)


            case Movement_State.TURNING:

                msg = Twist()
                msg.angular.z = self.turn_direction * ANGULAR_VELOCITY
                self.cmd_vel_publisher.publish(msg)

                yaw_difference = angles.normalize_angle(self.yaw - self.previous_yaw)

                if math.fabs(yaw_difference) >= math.radians(self.turn_angle):
                    self.goal_distance = random.uniform(1.0, 2.0)
                    self.state = Movement_State.FORWARD
                    self.get_logger().info(f"Finished turning, driving forward by {self.goal_distance:.2f} metres")


            case Movement_State.STATIONARY:
                msg = Twist()
                msg.angular.z = 0 * ANGULAR_VELOCITY
                msg.linear.x = 0 * LINEAR_VELOCITY
                self.cmd_vel_publisher.publish(msg)

                self.movement_state = Movement_State.FORWARD
                self.get_logger().info(f"Transitioning to FORWARD state from Stationary")

            case _:
                pass

    def is_robot_available():


        return 

    def is_robot_home():
        

        return 

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