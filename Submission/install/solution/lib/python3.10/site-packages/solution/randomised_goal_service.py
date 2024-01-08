import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException

import sys
import random
import math

from solution_interfaces.srv import RandomGoal

class RandomisedGoalService(Node):

    def __init__(self):
        super().__init__('randomised_goal_service')
        self.srv = self.create_service(RandomGoal, 'random_goal', self.random_goal_callback)

    def random_goal_callback(self, request, response):
        # Extracting the initial position values
        x = request.x
        y = request.y

        self.get_logger().info(f'Incoming request for random goal...')
        self.get_logger().info(f'Current Point: X - {x} , Y - {y}')

        # Generating a random angle in radians
        random_angle = random.uniform(0, 2 * 3.14159)
        random_distance = random.uniform(0.25, 0.5)

        # Calculating the new position on the robot's radius of between 0.5 and 1.0
        response.new_x = x + random_distance * math.cos(random_angle)
        response.new_y = y + random_distance * math.sin(random_angle)
        response.angle = random_angle
        self.get_logger().info('Returning request with random goal...')

        return response


def main():
    rclpy.init()

    node = RandomisedGoalService()
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