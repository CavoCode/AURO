import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription, LaunchContext
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, GroupAction, LogInfo, OpaqueFunction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare, LaunchConfiguration
from launch_ros.actions import Node
package_name = 'solutions'

def group_action(context : LaunchContext):
    num_robots = int(context.launch_configurations['num_robots'])

    robots_list = {}

    match num_robots:
        case 1:
            robots_list = ["robot1"]
        case 2:
            robots_list = ["robot1", "robot2"] 
        case _:
            robots_list = ["robot1", "robot2", "robot3"]

    bringup_cmd_group = []

    for robot_name in robots_list:
        group = GroupAction(
            Node(
                package='solution',
                executable='robot_controller',
                output='screen',
                namespace=robot_name)
        )
        
        bringup_cmd_group.append(group)

    return bringup_cmd_group


def generate_launch_description():

    num_robots = LaunchConfiguration('num_robots')

    declare_sol_num_robots_cmd = DeclareLaunchArgument(
        'num_robots',
        default_value='1',
        description='Number of robots to spawn')

    assessment_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare('assessment'),
                'launch',
                'assessment_launch.py'
                ])
        ),
        launch_arguments={'num_robots': num_robots,
                          'visualise_sensors': 'false',
                          'use_rviz': 'true',
                          'obstacles': 'true',
                          'item_manager': 'true',
                          'random_seed': '0',
                          }.items()
    )

    bringup_sol_cmd_group = OpaqueFunction(function=group_action)

    ld = LaunchDescription()

    ld.add_action(declare_sol_num_robots_cmd)
    ld.add_action(assessment_cmd)
    ld.add_action(bringup_sol_cmd_group)

    return ld
