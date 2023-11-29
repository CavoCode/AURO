# Based on: https://github.com/ros-planning/navigation2/blob/humble/nav2_simple_commander/nav2_simple_commander/example_nav_to_pose.py

import sys

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.duration import Duration

from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from solution_interfaces.msg import Goal

from enum import Enum

class State(Enum):
    IDLE = 0
    SET_GOAL = 1
    NAVIGATING = 2

class SimpleCommander(Node):

    def __init__(self):
        super().__init__('simple_commander')

        

        self.state = State.IDLE

        self.navigator = BasicNavigator()

        self.initial_pose = PoseStamped()
        self.goal = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = self.get_clock().now().to_msg()
        initial_pose.pose.position.x = -2.0
        initial_pose.pose.position.y = -0.5
        initial_pose.pose.orientation.z = 0.0
        initial_pose.pose.orientation.w = 1.0
        self.navigator.setInitialPose(initial_pose)

        self.navigator.waitUntilNav2Active()

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.goal_subscriber = self.create_subscription(
            PoseStamped,
            '/goal_pose',
            self.goal_callback,
            10)

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.goal_status_publisher = self.create_publisher(Goal, '/goal_status', 10)

        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)

    def goal_callback(self, msg):
        self.goal_pose = msg

    def control_loop(self):

        match self.state:

            case State.IDLE:


            case State.SET_GOAL:
                self.navigator.goToPose(self.goal_pose)

                self.state = State.NAVIGATING
            case State.NAVIGATING:

                if not self.navigator.isTaskComplete():
                    feedback = self.navigator.getFeedback()
                    print('Estimated time of arrival: ' + '{0:.0f}'.format(Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9) + ' seconds.')
                else:

                    result = self.navigator.getResult()

                    if result == TaskResult.SUCCEEDED:
                        print('Goal succeeded!')
                    elif result == TaskResult.CANCELED:
                        print('Goal was canceled!')
                    elif result == TaskResult.FAILED:
                        print('Goal failed!')
                    else:
                        print('Goal has an invalid return status!')

            case _:
                pass

    def destroy_node(self):
        self.get_logger().info(f"Shutting down")
        self.navigator.lifecycleShutdown()
        super().destroy_node()
        

def main(args=None):

    rclpy.init(args = args)

    node = SimpleCommander()

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