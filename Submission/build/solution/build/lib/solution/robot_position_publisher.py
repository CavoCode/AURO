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

    def __init__(self):
        super().__init__('robot_position')

        ##########################
        ## Initialise variables ##
        ##########################

        self.pose = Pose()
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.robot_position_publisher = self.create_publisher(RobotPubPosition, 'robot_position', 10)

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)

    def control_loop(self):
        try:
            t = self.tf_buffer.lookup_transform(
                'map',
                'base_footprint',
                rclpy.time.Time())
            
            x = t.transform.translation.x
            y = t.transform.translation.y

            (roll, pitch, yaw) = euler_from_quaternion([t.transform.rotation.x,
                                                        t.transform.rotation.y,
                                                        t.transform.rotation.z,
                                                        t.transform.rotation.w])
            
            self.get_logger().info(f"Robot currently at: X({x}), Y({y})")
            
            self.pose.position.x = x
            self.pose.position.y = y

            msg = RobotPubPosition()
            msg.pose = self.pose
            self.robot_position_publisher.publish(msg)

        except TransformException as e:
            self.get_logger().info(f"{e}")

    def destroy_node(self):
        self.get_logger().info(f"Shutting down")
        super().destroy_node()

def main(args=None):

    rclpy.init(args = args)
    node = RobotPosition()

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
