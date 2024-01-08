import sys
import math

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.duration import Duration

from geometry_msgs.msg import Point, Pose, PointStamped
from assessment_interfaces.msg import ItemHolders, ItemHolder, Item, ItemList
from solution_interfaces.msg import ItemAssessment, RobotStart
from nav_msgs.msg import Odometry

from tf_transformations import euler_from_quaternion, quaternion_from_euler

class ItemAssessor(Node):

    def __init__(self):
        super().__init__('item_assessor')

        ####################################
        ## Initialise Parameter Arguments ##
        ####################################

        self.declare_parameter('robot_name', rclpy.Parameter.Type.STRING)
        self.robot_name = self.get_parameter('robot_name').value

        ##########################
        ## Initialise variables ##
        ##########################

        self.pose = Pose()
        self.yaw = 0.0

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
        
        self.odom_subscriber = self.create_subscription(
            Odometry,
            'odom',
            self.odom_callback,
            10
        )

        self.robot_controller_subscriber = self.create_subscription(
            RobotStart,
            'robot_start_trigger',
            self.robot_start_callback,
            10
        )
        
        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.item_assessor_publisher = self.create_publisher(ItemAssessment, 'item_assessor', 10)
        
        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
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

    def odom_callback(self, msg):
        self.pose = msg.pose.pose # Store the pose in a class variable

        (roll, pitch, yaw) = euler_from_quaternion([self.pose.orientation.x,
                                                    self.pose.orientation.y,
                                                    self.pose.orientation.z,
                                                    self.pose.orientation.w])
        
        self.yaw = yaw # Store the yaw in a class variable   

    def robot_start_callback(self, msg):
        self.start_control_loop = msg.start_assessment


    ##################
    ## Control Loop ##
    ##################

    def control_loop(self):
        if self.start_control_loop == True:
            self.get_logger().info(f"Assessing Items...")

            if self.robot_holding:
                self.get_logger().info(f"Holding Value: {self.holding_value}")
                better_item_found = self.assess_items(self.holding_value)
            else:
                self.get_logger().info(f"Goal Value: {self.goal_value}")
                better_item_found = self.assess_items(self.goal_value)

            if better_item_found:

                self.get_logger().info(f"Better Item found...")

                angle = self.goal_item.x / 320.0
                goal_point = Point()
                goal_point.x = self.pose.position.x + self.goal_distance * math.cos(angle)
                goal_point.y = self.pose.position.y + self.goal_distance * math.sin(angle)
                
                self.get_logger().info(f"Found at: X({goal_point.x}), Y({goal_point.y})")
                self.get_logger().info(f"Robot at: X({self.pose.position.x}), Y({self.pose.position.y})")
                self.get_logger().info(f"Distance to New Item: {self.goal_distance}")

                item_goal_point = PointStamped()
                item_goal_point.header.frame_id = 'new_item'
                item_goal_point.header.stamp = self.get_clock().now().to_msg()   
                item_goal_point.point = goal_point

                item_assessment = ItemAssessment()
                item_assessment.goal_point_stamped = item_goal_point
                item_assessment.goal_type = 'Collect'

                self.get_logger().info(f"Publishing to /item_assessor...")
                self.item_assessor_publisher.publish(item_assessment)
        else:
            self.get_logger().info(f"Waiting for robot controller to be ready...")

    def assess_items(self, value_to_compare, goal_distance_threshold = 0.5, item_distance_threshold = 1):
        better_item_found = False
        distance_to_item = 0

        for i in range(0, len(self.items.data)):
            item = self.items.data[i]

            distance_to_item = 0.25 * (69.0 * (float(item.diameter) ** -0.89))

            if self.goal_item.value != 0:
                if distance_to_item < self.goal_distance or (self.goal_distance > goal_distance_threshold and distance_to_item < item_distance_threshold):
                    # Assess if the item is better and closer
                    if item.value > value_to_compare:
                        self.goal_item = item
                        self.goal_value = item.value
                        self.goal_distance = distance_to_item
                        better_item_found = True
                
            else:
                self.goal_item = item
                self.goal_value = item.value
                self.goal_distance = distance_to_item
                better_item_found = True

        return better_item_found
    
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
