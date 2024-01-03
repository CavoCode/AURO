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
from geometry_msgs.msg import Twist, Pose
from std_msgs.msg import Header
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from solution_interfaces.msg import GoalStatus, StringWithPose, GoalPosition, LocateHome

#Math
from tf_transformations import euler_from_quaternion, transforms3d
import angles
from enum import Enum
import random
import math

######################
## Global Variables ##
######################

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

############
## States ##
############

class State(Enum):
    IDLE = 0
    MOVING_TO_GOAL = 1
    LOCATE_HOME = 2
    TURNING_TO_AVOID_OBSTACLE = 3

##########
## Node ##
##########

class RobotController(Node):

    ####################
    ## Initialisation ##
    ####################

    def __init__(self):
        super().__init__('robot_controller')

        ##########################
        ## Initialise variables ##
        ##########################

        self.state = State.IDLE
        self.previous_state = self.state

        self.pose = Pose() #Current pose (position and orientation), relative to the odom reference frame
        self.previous_pose = Pose() #Store a snapshot of the pose for comparision against future poses
        self.yaw = 0.0
        self.previous_yaw = 0.0
        self.turn_angle = 0.0
        self.turn_direction = TURN_LEFT
        self.scan_triggered = [False] * 4

        self.goal_pose = Pose()
        self.goal_pose_updated = False
        self.current_goal_type = 'Search'

        self.homeZone_visible = False

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.goal_subscriber = self.create_subscription(
            GoalPosition,
            '/goal_pose',
            self.goal_pose_callback,
            10)
        
        self.locateHome_subscriber = self.create_subscription(
            LocateHome,
            '/locate_home',
            self.locate_home_callback,
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
        self.pose_publisher = self.create_publisher(Pose, '/current_pose', 10)
        self.goal_publisher = self.create_publisher(GoalStatus, '/goal_status', 10)

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1
        self.timer = self.create_timer(self.timer_period, self.control_loop)
        self.mini_timer = 0

    ############################
    ## Subscription Callbacks ##
    ############################

    def goal_pose_callback(self, msg):
        # Define a small time window (in seconds) for matching timestamps
        time_window = 0.005  # Adjust as needed (5 milliseconds in this example)

        # Get the current clock time
        current_time = self.get_clock().now().to_msg()

        if abs((msg.poseStamped.header.stamp - current_time).to_sec()) < time_window:
            self.goal_pose = msg.poseStamped.pose
            self.current_goal_type = msg.goalType
            self.get_logger().info(f"Updated the goal position with latest from /goal_pose")
            self.goal_pose_updated = True
        else:
            self.goal_pose_updated = False

    def locate_home_callback(self, msg):
        # Define a small time window (in seconds) for matching timestamps
        time_window = 0.005  # Adjust as needed (5 milliseconds in this example)

        # Get the current clock time
        current_time = self.get_clock().now().to_msg()

        if abs((msg.header.stamp - current_time).to_sec()) < time_window:
            if msg.locateHome == False:
                self.get_logger().info(f"State Manager cannot locate home - Moving Accordingly")
                self.state = State.LOCATE_HOME

            else:
                self.state = State.IDLE

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

    def control_loop(self):

        #Update /current_pose
        self.pose_publisher.publish(self.pose)

        # Send message to rviz_text_marker node
        marker_input = StringWithPose()
        marker_input.text = str(self.state) # Visualise robot movement state as an RViz marker
        marker_input.pose = self.pose # Set the pose of the RViz marker to track the robot's pose
        self.marker_publisher.publish(marker_input)

        self.get_logger().info(f"State: {self.state}")

        match self.state:
            case State.IDLE:
                self.stop_robot()
                self.goal_message('IDLE', 'None')

                if self.goal_pose_updated == True:
                    self.previous_state = self.state
                    self.state = State.MOVING_TO_GOAL
                    self.goal_pose_updated = False
                else:
                    return

            case State.MOVING_TO_GOAL:
                self.goal_message('Processing')

                if self.check_collision():
                    self.get_logger().info(f"Collision Detected - Acting accordingly")
                    self.goal_message('Collison Detected')
                    return
                
                distance_to_goal = math.sqrt((self.pose.position.x - self.goal_pose.position.x)**2 + (self.pose.position.y - self.goal_pose.position.y)**2)
                angle_to_goal = math.atan2(self.goal_pose.position.y - self.pose.position.y, self.goal_pose.position.x - self.pose.position.x)

                cmd_vel_msg = Twist()
                cmd_vel_msg.linear.x = min(0.5, 0.1 * distance_to_goal)
                cmd_vel_msg.angular.z = 0.1 * angle_to_goal
                self.cmd_vel_publisher.publish(cmd_vel_msg)

                if distance_to_goal < 0.1:
                    self.previous_state = self.state
                    self.state = State.IDLE
                    self.get_logger().info("Goal Reached")
                    
                    self.goal_message('Completed')

                    self.stop_robot()

            case State.LOCATE_HOME:
                self.get_logger().info(f"Attempting to locate Home Zone")
                self.goal_message('Finding Home', 'Home')

                if self.check_collision():
                    self.get_logger().info(f"Collision Detected - Acting accordingly")
                    self.goal_message('Collison Detected', 'Home')
                    return

                if self.turn_check_complete == False:
                    msg_turn = Twist()
                    msg_turn.angular.z = 1 * ANGULAR_VELOCITY #Turn Left
                    self.cmd_vel_publisher.publish(msg_turn)

                    yaw_difference = angles.normalize_angle(self.yaw - self.previous_yaw)

                    if math.fabs(yaw_difference) >= math.radians(self.turn_angle):
                        self.stop_robot()
                        self.get_logger().info(f"Homing Turn Check - complete: No Home Zone")
                        self.get_logger().info(f"Moving for better vantage")
                        self.turn_check_complete == True
                        return
                    
                else:
                    msg_fwd = Twist()
                    msg_fwd.linear.x = LINEAR_VELOCITY

                    fwd_duration = 1
                    if fwd_duration > self.mini_timer:
                        self.mini_timer += 0.1
                    else:
                        self.stop_robot()
                        self.get_logger().info(f"Finished moving forward, completing turn check for home")
                        self.mini_timer = 0
                        self.turn_angle = 360 + random.uniform(150, 170)
                        self.turn_check_complete = False
                        return
            
            case State.TURNING_TO_AVOID_OBSTACLE:
                msg = Twist()
                msg.angular.z = self.turn_direction * ANGULAR_VELOCITY
                self.cmd_vel_publisher.publish(msg)

                yaw_difference = angles.normalize_angle(self.yaw - self.previous_yaw)

                if math.fabs(yaw_difference) >= math.radians(self.turn_angle):
                    self.stop_robot()
                    self.get_logger().info(f"Finished turning to avoid obstacle, resuming previous state")
                    self.goal_publisher.publish('Collision Avoided')

                    # Transition back to the previous state
                    if self.previous_state == State.MOVING_TO_GOAL:
                        self.previous_state = self.state
                        self.state == State.MOVING_TO_GOAL
                    elif self.previous_state == State.LOCATE_HOME:
                        self.previous_state = self.state
                        self.state == State.LOCATE_HOME
                    else:
                        self.previous_state = self.state
                        self.state = State.IDLE

    ################
    ## Procedures ##
    ################

    def goal_message(self, status, goal_type):
        goal_status = GoalStatus()
        goal_status.status = status

        if goal_type != None:
            goal_status.goalType = goal_type
        else:
            goal_status.goalType = self.current_goal_type

        self.goal_publisher.publish(goal_status)

    def check_collision(self):
        # Check for obstacle detection during forward motion
        if self.scan_triggered[SCAN_FRONT]:
            self.get_logger().info("Detected obstacle in front, stopping and entering turning state")
            self.previous_yaw = self.yaw
            self.previous_state = self.state
            self.state = 'TURNING_TO_AVOID_OBSTACLE'
            self.turn_angle = random.uniform(150, 170)
            self.turn_direction = random.choice(['LEFT', 'RIGHT'])
            self.stop_robot()
            return True

        # Check for obstacle detection on the left or right side
        if self.scan_triggered[SCAN_LEFT] or self.scan_triggered[SCAN_RIGHT]:
            self.get_logger().info("Detected obstacle on the side, stopping and entering turning state")
            self.previous_yaw = self.yaw
            self.previous_state = self.state
            self.state = 'TURNING_TO_AVOID_OBSTACLE'
            self.turn_angle = random.uniform(45, 90)

            if self.scan_triggered[SCAN_LEFT] and self.scan_triggered[SCAN_RIGHT]:
                self.turn_direction = random.choice(['LEFT', 'RIGHT'])
                self.get_logger().info("Detected obstacle on both sides, turning " + ("left" if self.turn_direction == 'LEFT' else 'right') + f" by {self.turn_angle:.2f} degrees")
            elif self.scan_triggered[SCAN_LEFT]:
                self.turn_direction = 'RIGHT'
                self.get_logger().info(f"Detected obstacle on the left, turning right by {self.turn_angle} degrees")
            else:  # self.scan_triggered[SCAN_RIGHT]
                self.turn_direction = 'LEFT'
                self.get_logger().info(f"Detected obstacle on the right, turning left by {self.turn_angle} degrees")
            self.stop_robot()
            return True

        return False

    def stop_robot(self):
        cmd_vel_msg = Twist()
        self.cmd_vel_publisher.publish(cmd_vel_msg)

    ##############
    ## Shutdown ##
    ##############

    def destroy_node(self):
        msg = Twist()
        self.cmd_vel_publisher.publish(msg)
        self.get_logger().info(f"Stopping: {msg}")
        super().destroy_node()

##########
## Main ##
##########

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