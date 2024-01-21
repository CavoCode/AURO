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
        self.goal_angle = 0.0
        self.srv = self.create_service(ItemAssessment, 'item_assessor', self.item_assessor_callback)

    def item_assessor_callback(self, request, response):
        value_to_compare = request.value
        items = request.items
        
        # Extracting the item list
        for i in range(0, len(items.data)):
            item = items.data[i]
            distance_to_item = distance_to_item = ((self.focal_length * self.actual_diameter) / float(item.diameter))
            angle = ((1.085595/2) * ((item.x * (640/2)) / 640)) * (math.pi / 180)
            #angle = item.x / 320.0

            if self.goal_item.value != 0:
                # Assess if the item is better and closer
                if distance_to_item < self.goal_distance:
                    if item.value > value_to_compare:
                        self.goal_item = item
                        self.goal_distance = distance_to_item
                        self.goal_angle = angle
                        value_to_compare = item.value

                    elif item.value == value_to_compare:
                        self.goal_item = item
                        self.goal_distance = distance_to_item
                        self.goal_angle = angle
                        value_to_compare = item.value

            else:
                self.goal_item = item
                self.goal_distance = distance_to_item
                self.goal_angle = angle
                value_to_compare = item.value
            
        self.get_logger().info(f'Incoming request for random goal...')

        # Setting response as new item and it's distance
        response.item = self.goal_item
        response.distance = self.goal_distance
        response.angle = self.goal_angle

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