import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException

import sys
import math

from assessment_interfaces.msg import Item, ItemList
from solution_interfaces.srv import ItemAssessment

class ItemAssessmentService(Node):

    def __init__(self):
        super().__init__('item_assessor_service')
        self.focal_length = 640 / (2 * math.tan(1.085595  / 2))
        self.actual_diameter = 0.15
        self.goal_item = Item()
        self.goal_distance = 0.0
        self.srv = self.create_service(ItemAssessment, 'item_assessor', self.item_assessor_callback)

    def item_assessor_callback(self, request, response):
        value_to_compare = request.value
        items = request.items
        
        # Extracting the item list
        for i in range(0, len(items.data)):
            item = items.data[i]
            distance_to_item = 0.25 + ((self.focal_length * self.actual_diameter) / float(item.diameter))

            # Combine conditions to reduce nested if-else blocks
            if (self.goal_item.value == 0 or distance_to_item < self.goal_distance) and item.value >= value_to_compare:
                # Update the goal item, distance, angle, and comparison value
                self.goal_item, self.goal_distance, value_to_compare = item, distance_to_item, item.value
            elif item.value > value_to_compare and distance_to_item < 2.0:
                # Update for items with higher value but within a specific distance range
                self.goal_item, self.goal_distance, value_to_compare = item, distance_to_item, item.value
            
        self.get_logger().info(f'Incoming request for random goal...')

        # Setting response as new item and it's distance
        response.item = self.goal_item
        response.distance = self.goal_distance

        self.get_logger().info(f'Item found of value: {self.goal_item.value} & at distance: {self.goal_distance}')
        self.get_logger().info('Returning request with new item...')

        return response
    

def main():
    rclpy.init()

    node = ItemAssessmentService()
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