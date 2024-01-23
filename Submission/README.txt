################################################
Autonomous Mobile Robot Item Retrieval System
################################################

~~~~~~~~
Overview
~~~~~~~~

This document provides comprehensive guidance on setting up and using an Autonomous Mobile Robot system in a simulated ROS2 environment. The system's primary function is to navigate autonomously, retrieve items scattered across the simulated landscape, and return them to a designated zone, efficiently avoiding obstacles. Each robot in the system can transport only one item at a time. A new item appears in the environment whenever an item is successfully returned.

~~~~~~~~~~~~~~~~~~~
Installation Steps
~~~~~~~~~~~~~~~~~~~
---------------
Prerequisites
---------------

Ensure the following prerequisites are met:

- Operating System: Ubuntu 22.04 LTS
- Required Applications:
    - ROS-2 Humble Hawksbill
    - Gazebo Classic 11
    - Python3 & rclpy
    - RViz
- Necessary Packages:
    - assessment
    - assessment_interfaces
    - tf_relay
    - tf_transformations
    - Turtlebot3 packages
    - Navigation2 packages

--------------------------------------
Step 1: Install ROS-2 Humble Hawksbill
--------------------------------------

Begin by installing ROS2 Humble Hawksbill on your Linux system. Detailed instructions are available at the ROS2 documentation site: https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html. This guide is beginner-friendly and covers essential setup procedures.

---------------------------------------
Step 2: Install Additional Applications
---------------------------------------

- Gazebo Classic 11:
  Install using: "sudo apt install gazebo"
  Verify the installation with: "gazebo"

- Python3:
  Usually pre-installed on Ubuntu 22.04 LTS. Confirm with: "python3 --version"
  If absent, install using: "sudo apt install python3"
  Install 'rclpy' if not included in ROS2 installation: "pip install rclpy"

- RViz:
  Install RViz (if not included in ROS2): "sudo apt install ros-humble-rviz"

-------------------------------------
Step 3: Install Required ROS Packages
-------------------------------------

- Assessment Packages:
  Clone from https://github.com/alanmillard/auro-practicals/tree/item_manager to a new directory: 
    "mkdir ~/ROS2-additionals/auro-practicals/src"
  Remove 'solution' and 'solution_interfaces' folders to avoid conflicts.
  Build with:
    "colcon build --symlink-install"
    "echo 'source ~/ROS2-additionals/auro-practicals/install/local_setup.bash' >> ~/.bashrc"

- TF_Transformations:
  Clone from https://github.com/DLu/tf_transformations.git to a separate folder and build:
    "mkdir ~/ROS2-additionals/tf_transform/src/tf_transformations"
    "colcon build --symlink-install"
    "echo 'source ~/ROS2-additionals/tf_transform/install/local_setup.bash' >> ~/.bashrc"

- Turtlebot3:
  Create a workspace and clone Turtlebot3 packages:
    "mkdir -p ~/ROS2-additionals/turtlebot3_ws/src"
    "cd ~/ROS2-additionals/turtlebot3_ws/src/"
    Clone the Turtlebot3 repositories and build:
    "git clone -b humble-devel [respective repositories]"
    "colcon build --symlink-install"
    Configure environment variables in ~/.bashrc for Turtlebot3 and Gazebo.

- Navigation2:
  Install Navigation2 packages:
    "sudo apt install ros-humble-[navigation2 packages]"

Re-source ~/.bashrc after installing and building all packages.

~~~~~~~~~~~~~~~~~~~~
Building the Package
~~~~~~~~~~~~~~~~~~~~

After setting up the environment, proceed to build the provided solution.

- Create a new workspace for the solution: "mkdir ~/solution/"
- Copy the 'src' folder from the submission.zip to "~/solution/src"
- Inside "~/solution/", run "colcon build"
- Source the built packages: "source ~/solution/install/local_setup.bash"
- Verify package installation with "ros2 pkg list"

~~~~~~
Usage
~~~~~~

To operate the system:

- Launch the solution with: "ros2 launch solution solution_nav2_launch.py"
- This command will open additional tabs, RViz, and Gazebo.
- To deploy multiple robots (up to 3), use the 'num_robots' parameter:
  Example: "ros2 launch solution solution_nav2_launch.py num_robots:=2"
