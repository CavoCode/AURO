#!/usr/bin/env python3

import sys

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException

from geometry_msgs.msg import Pose
from solution_interfaces.msg import RobotPubPosition

from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

from tf_transformations import euler_from_quaternion

class RobotPosition(Node):
    """
    A ROS2 node for tracking and publishing the robot's position.

    This node listens for transform information about the robot's position in the map frame,
    converts it to a Pose message, and publishes this information for other nodes to use.
    """

    def __init__(self):
        """
        Initialize the RobotPosition node.
        """

        # Call the constructor of the parent class (Node)
        super().__init__('robot_position')

        ##########################
        ## Initialise variables ##
        ##########################

        # Initialize pose variables to store the current and previous positions of the robot
        self.pose = Pose()
        self.prev_pose = Pose()

        # Set up a TransformListener to listen to transform messages between frames
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        # Create a ROS publisher to publish the robot's position
        self.robot_position_publisher = self.create_publisher(RobotPubPosition, 'robot_position', 10)

        ######################
        ## Initialise Timer ##
        ######################

        # Set up a timer for the control loop with a frequency of 10 Hz (0.1-second intervals)
        self.timer_period = 0.1  # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)

    def control_loop(self):
        """
        Control loop for the RobotPosition node.
        
        This method is called periodically based on the timer set in __init__. 
        It retrieves the current position of the robot, logs it, and publishes it.
        """
        try:
            # Look up the current transform from the map frame to the robot's base footprint
            t = self.tf_buffer.lookup_transform('map', 'base_footprint', rclpy.time.Time())

            # Extract the robot's current x, y coordinates
            x = t.transform.translation.x
            y = t.transform.translation.y

            # Convert the quaternion orientation to roll, pitch, yaw
            (roll, pitch, yaw) = euler_from_quaternion([t.transform.rotation.x,
                                                        t.transform.rotation.y,
                                                        t.transform.rotation.z,
                                                        t.transform.rotation.w])

            # Log the current position
            self.get_logger().info(f"Robot currently at: X({x}), Y({y})")

            # Update the previous and current pose
            self.prev_pose = self.pose
            self.pose.position.x = x
            self.pose.position.y = y

            # Create and publish a message with the current pose and yaw
            msg = RobotPubPosition()
            msg.pose = self.pose
            msg.yaw = yaw
            self.robot_position_publisher.publish(msg)

        except TransformException as e:
            # Log any exceptions that occur during the transform lookup
            self.get_logger().info(f"{e}")

    def destroy_node(self):
        """
        Shutdown routine for the RobotPosition node.
        
        This method ensures a clean shutdown of the node, logging the shutdown process.
        """
        self.get_logger().info("Shutting down")
        super().destroy_node()

def main(args=None):
    """
    Main function to initialize and run the RobotPosition ROS2 node.
    """
    # Initialize the ROS2 Python client library
    rclpy.init(args=args)

    # Create an instance of the RobotPosition node
    node = RobotPosition()

    try:
        # Spin the node to execute its control loop
        rclpy.spin(node)
    except KeyboardInterrupt:
        # Handle keyboard interrupt (Ctrl+C) gracefully
        pass
    except ExternalShutdownException:
        # Handle external shutdown signal and exit
        sys.exit(1)
    finally:
        # Ensure proper shutdown of the node and ROS2 library
        node.destroy_node()
        rclpy.try_shutdown()

if __name__ == '__main__':
    # Run the main function when the script is executed
    main()
