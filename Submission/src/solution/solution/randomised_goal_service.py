#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException

import sys
import random
import math

from solution_interfaces.srv import RandomGoal

class RandomisedGoalService(Node):
    """
    A ROS2 service node for generating randomized goals.

    This node provides a service that takes the current position as input and 
    generates a random goal within a specified range from that position.
    """

    def __init__(self):
        """
        Initialize the RandomisedGoalService node.
        """
        # Call the constructor of the parent class (Node)
        super().__init__('randomised_goal_service')

        # Create a ROS service for random goal generation
        self.srv = self.create_service(RandomGoal, 'random_goal', self.random_goal_callback)

    def random_goal_callback(self, request, response):
        """
        Callback function for the random goal generation service.

        Args:
            request: The request message containing the current position (x, y) of the robot.
            response: The response message to be filled with the new random goal position and angle.

        This function calculates a new position based on a random angle and distance
        from the current position and sets it as the goal.
        """
        # Extracting the current position from the request
        x = request.x
        y = request.y

        # Log the incoming request details
        self.get_logger().info('---------------------------------------------------------------------------------')
        self.get_logger().info('Incoming request for random goal...')
        self.get_logger().info(f'Current Point: X - {x} , Y - {y}')
        
        # Generating a random angle (in radians) and distance
        random_angle = self.generate_random_angle(x,y)
        random_distance = random.uniform(1.0, 1.5)  # Distance in meters

        # Calculating the new position based on the random angle and distance
        response.new_x = x + (random_distance * math.cos(random_angle))
        response.new_y = y + (random_distance * math.sin(random_angle))
        response.angle = random_angle

        # Log the calculated random goal
        self.get_logger().info(f'Random Goal set: X - {response.new_x}, Y - {response.new_y} at angle - {random_angle}')
        self.get_logger().info('Returning request with random goal...')

        return response

    def generate_random_angle(self, x, y):
        # Define angle ranges based on robot's current position
        # Angles are measured clockwise from the positive-x axis (north)

        if x < -3.5:  # Robot is in the south
            if y < -2:
                # South-East: steer to the North-West
                angle_min, angle_max = -(math.pi/2), 0
            elif y > 2:
                # South-West: steer to the North-East
                angle_min, angle_max = 0, math.pi / 2
            else:
                # Directly South: steer anywhere in the northern hemisphere
                angle_min, angle_max = -(math.pi/2), math.pi/2

        elif x > 2.5:  # Robot is in the north
            if y < -2:
                # North-East: steer to the South-West
                angle_min, angle_max = math.pi, 3 * (math.pi/2)
            elif y > 2:
                # North-West: steer to the South-East
                angle_min, angle_max = math.pi / 2, math.pi
            else:
                # Directly North: steer anywhere in the southern hemisphere
                angle_min, angle_max = math.pi / 2, 3 * (math.pi / 2)

        elif y < -2:  # Robot is in the east
            # East: steer to the West
            angle_min, angle_max = math.pi, 2 * math.pi

        elif y > 2:  # Robot is in the west
            # West: steer to the East
            angle_min, angle_max = 0, math.pi

        else:
            # Robot is approximately in the center: can go in any direction
            angle_min, angle_max = 0, 2 * math.pi

        # Generate a random angle within the specified range
        random_angle = random.uniform(angle_min, angle_max)

        return random_angle
def main():
    """
    Main function to initialize and run the RandomisedGoalService ROS2 node.
    """
    # Initialize the ROS2 Python client library
    rclpy.init()

    # Create an instance of the RandomisedGoalService node
    node = RandomisedGoalService()

    try:
        # Spin the node to process callbacks
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