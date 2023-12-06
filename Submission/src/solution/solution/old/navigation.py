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

        ##########################
        ## Initialise variables ##
        ##########################

        self.state = State.IDLE
        self.navigator = BasicNavigator()
        self.initial_pose = PoseStamped()
        self.goal = PoseStamped()

        ################################
        ## Initialise ROS Subscribers ##
        ################################

        self.goal_subscriber = self.create_subscription(
            PoseStamped,
            '/goal_pose',
            self.goal_callback,
            10)
        
        self.pose_subscriber = self.create_subscription(
            PoseStamped,
            '/pose_pub',
            self.pose_callback,
            10)

        ###############################
        ## Initialise ROS Publishers ##
        ###############################

        self.goal_status_publisher = self.create_publisher(Goal, '/goal_status', 10)

        ######################
        ## Initialise Timer ##
        ######################

        self.timer_period = 0.1 # 100 milliseconds = 10 Hz
        self.timer = self.create_timer(self.timer_period, self.control_loop)

    ############################
    ## Subscription Callbacks ##
    ############################

    def goal_callback(self, msg):
        self.goal_pose = msg

    def pose_callback(self, msg):
        if self.initial_pose != msg:
            self.goal_updated = True
            self.initial_pose = msg
            self.navigator.setInitialPose(self.initial_pose)
            self.navigator.waitUntilNav2Active()

    ##################
    ## Control Loop ##
    ##################

    def control_loop(self):

        match self.state:

            case State.IDLE:
                if self.goal_updated == True:
                    self.state = State.SET_GOAL
                else:
                    self.goal_status_publisher.publish('Ready')
                    return

            case State.SET_GOAL:
                self.goal_updated = False
                self.navigator.goToPose(self.goal_pose)
                self.state = State.NAVIGATING

            case State.NAVIGATING:

                if not self.navigator.isTaskComplete():
                    feedback = self.navigator.getFeedback()
                    print('Estimated time of arrival: ' + '{0:.0f}'.format(Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9) + ' seconds.')
                    self.goal_status_publisher.publish('Processing')
                else:

                    result = self.navigator.getResult()

                    if result == TaskResult.SUCCEEDED:
                        print('Goal succeeded!')
                        self.goal_status_publisher.publish('Succeeded')
                    elif result == TaskResult.CANCELED:
                        print('Goal was canceled!')
                        self.goal_status_publisher.publish('Cancelled')
                    elif result == TaskResult.FAILED:
                        print('Goal failed!')
                        self.goal_status_publisher.publish('Failed')
                    else:
                        print('Goal has an invalid return status!')
                        self.goal_status_publisher.publish('Invalid')

                    self.state = State.IDLE

            case _:
                pass

    ##############
    ## Shutdown ##
    ##############

    def destroy_node(self):
        self.get_logger().info(f"Shutting down")
        self.navigator.lifecycleShutdown()
        super().destroy_node()
        
##########
## Main ##
##########

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