import sys
import math

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException

from geometry_msgs.msg import Point, Pose, PointStamped
from assessment_interfaces.msg import ItemHolders, ItemHolder, Item, ItemList
from solution_interfaces.msg import ItemAssessment, RobotStart, RobotPubPosition

class ItemAssessor(Node):

    def __init__(self):
        super().__init__('item_assessor')

        ####################################
        ## Initialise Parameter Arguments ##
        ####################################

        self.declare_parameter('initial_pose', rclpy.Parameter.Type.DOUBLE_ARRAY)
        self.declare_parameter('robot_name', rclpy.Parameter.Type.STRING)

        init_pose = self.get_parameter('initial_pose').value
        self.robot_name = self.get_parameter('robot_name').value

        ##########################
        ## Initialise variables ##
        ##########################

        self.pose = Pose()
        self.pose.position.x = init_pose[0]
        self.pose.position.y = init_pose[1]

        self.start_control_loop = False
        self.robot_holding = False
        self.items = ItemList()
        self.goal_item = Item()
        self.goal_distance = 0
        self.goal_value = 0
        self.holding_value = 0

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.item_holder_subscriber = self.create_subscription(
            ItemHolders,
            '/item_holders',
            self.item_holder_callback,
            10
        )

        self.item_subscriber = self.create_subscription(
            msg_type=ItemList,
            topic='items',
            callback=self.item_callback,
            qos_profile=10,
            )
        
        self.robot_controller_subscriber = self.create_subscription(
            RobotStart,
            'robot_start_trigger',
            self.robot_start_callback,
            10
        )

        self.robot_position_subscriber = self.create_subscription(
            RobotPubPosition,
            'robot_position',
            self.robot_position_callback,
            10
        )

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.item_assessor_publisher = self.create_publisher(ItemAssessment, 'item_assessor', 10)
        
        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)
        
    ############################
    ## Subscription Callbacks ##
    ############################
        
    def item_holder_callback(self, msg):
        itemHolders = ItemHolders()
        itemHolders = msg

        itemHolder = ItemHolder()
        for itemHolder in itemHolders.data:
            if itemHolder.robot_id == self.robot_name and itemHolder.holding_item == True:
                self.robot_holding = True
                self.holding_value = itemHolder.item_value
                return

    def item_callback(self, msg):
        self.items = msg

    def robot_start_callback(self, msg):
        self.start_control_loop = msg.start_assessment

    def robot_position_callback(self, msg):
        self.pose = msg.pose

    ##################
    ## Control Loop ##
    ##################

    def control_loop(self):
        if self.start_control_loop == True:
            self.get_logger().info(f"Current Position: X({self.pose.position.x}), Y({self.pose.position.y})")
            self.get_logger().info(f"Assessing Items...")

            if self.robot_holding:
                better_item_found = self.assess_items(self.holding_value)
            else:
                better_item_found = self.assess_items(self.goal_value)

            if better_item_found:
                self.get_logger().info(f"--------------------------------------------")

                if self.robot_holding:
                    self.get_logger().info(f"Item of value {self.goal_value} found...")
                    self.get_logger().info(f"Still holding value {self.holding_value}")
                else:
                    self.get_logger().info(f"Item of value {self.goal_value} found...")

                angle = self.goal_item.x / 360.0
                goal_point = Point()
                goal_point.x = self.pose.position.x + (self.goal_distance * math.cos(angle))
                goal_point.y = self.pose.position.y + (self.goal_distance * math.sin(angle))
                
                self.get_logger().info(f"Found at: X({goal_point.x}), Y({goal_point.y})")
                self.get_logger().info(f"Distance to New Item: {self.goal_distance}")

                item_goal_point = PointStamped()
                item_goal_point.header.frame_id = 'new_item'
                item_goal_point.header.stamp = self.get_clock().now().to_msg()   
                item_goal_point.point = goal_point

                item_assessment = ItemAssessment()
                item_assessment.goal_point_stamped = item_goal_point
                item_assessment.goal_type = 'Collect'
                item_assessment.goal_angle = angle

                self.get_logger().info(f"Publishing to /item_assessor...")
                self.item_assessor_publisher.publish(item_assessment)
                self.get_logger().info(f"--------------------------------------------")
        else:
            self.get_logger().info(f"Waiting for robot controller to be ready...")

    def assess_items(self, value_to_compare):
        for i in range(0, len(self.items.data)):
            item = self.items.data[i]
            distance_to_item = 0.6 * (69.0 * (float(item.diameter) ** (-0.89)))

            if self.goal_item.value != 0:
                # Assess if the item is better and closer
                if item.value > value_to_compare and distance_to_item < self.goal_distance:
                    self.goal_item = item
                    self.goal_value = item.value
                    self.goal_distance = distance_to_item
                    return True
                 
            else:
                self.goal_item = item
                self.goal_value = item.value
                self.goal_distance = distance_to_item
                return True
            
        return False
    
    def destroy_node(self):
        self.get_logger().info(f"Shutting down")
        super().destroy_node()
        

def main(args=None):

    rclpy.init(args = args)
    node = ItemAssessor()

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
