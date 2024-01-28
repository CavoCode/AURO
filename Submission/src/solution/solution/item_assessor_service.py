import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException

import sys
import math

from assessment_interfaces.msg import Item, ItemList
from solution_interfaces.srv import ItemAssessment

class ItemAssessmentService(Node):
    """
    A ROS2 service node for assessing items and determining the best item to approach.

    This node provides a service that processes a list of items, calculates their distance,
    and determines which item should be the goal based on its value and distance.
    """

    def __init__(self):
        """
        Initialize the ItemAssessmentService node.
        """
        # Call the constructor of the parent class (Node)
        super().__init__('item_assessor_service')

        # Initialize variables used for distance calculation
        self.focal_length = 640 / (2 * math.tan(1.085595 / 2))  # Focal length calculation
        self.actual_diameter = 0.15  # Set the actual diameter of the items

        # Initialize variables to store the current goal item and its distance
        self.goal_item = Item()
        self.goal_distance = 0.0

        # Create a ROS service for item assessment
        self.srv = self.create_service(ItemAssessment, 'item_assessor', self.item_assessor_callback)

    def item_assessor_callback(self, request, response):
        """
        Callback function for the item assessment service.

        Args:
            request: The request message containing the items to be assessed and a comparison value.
            response: The response message to be filled with the selected item and its distance.

        The function processes each item, calculates its distance, and selects the best item
        based on the given criteria.
        """
        value_to_compare = request.value  # Value to compare for item selection
        items = request.items  # List of items to be assessed

        # Iterating through each item to assess its suitability
        for i in range(len(items.data)):
            item = items.data[i]
            # Calculate the distance to each item
            distance_to_item = 0.33 + ((self.focal_length * self.actual_diameter) / float(item.diameter))

            # Select the best item based on value and distance criteria
            if (self.goal_item.value == 0 or distance_to_item < self.goal_distance) and item.value >= value_to_compare:
                self.goal_item, self.goal_distance, value_to_compare = item, distance_to_item, item.value
            elif item.value > value_to_compare and distance_to_item < 2.0:
                self.goal_item, self.goal_distance, value_to_compare = item, distance_to_item, item.value

        self.get_logger().info('Incoming request for random goal...')

        # Populate the response with the selected item and its distance
        response.item = self.goal_item
        response.distance = self.goal_distance

        # Log information about the selected item
        self.get_logger().info(f'Item found of value: {self.goal_item.value} & at distance: {self.goal_distance}')
        self.get_logger().info('Returning request with new item...')

        return response
    

def main():
    """
    Main function to initialize and run the ItemAssessmentService ROS2 node.
    """
    # Initialize the ROS2 Python client library
    rclpy.init()

    # Create an instance of the ItemAssessmentService node
    node = ItemAssessmentService()

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