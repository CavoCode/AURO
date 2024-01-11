// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:msg/RobotPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_POSITION__STRUCT_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__solution_interfaces__msg__RobotPosition __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__msg__RobotPosition __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotPosition_
{
  using Type = RobotPosition_<ContainerAllocator>;

  explicit RobotPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    (void)_init;
  }

  explicit RobotPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::msg::RobotPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::msg::RobotPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::msg::RobotPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::msg::RobotPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::RobotPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::RobotPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::RobotPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::RobotPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::msg::RobotPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::msg::RobotPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__msg__RobotPosition
    std::shared_ptr<solution_interfaces::msg::RobotPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__msg__RobotPosition
    std::shared_ptr<solution_interfaces::msg::RobotPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotPosition_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotPosition_

// alias to use template instance with default allocator
using RobotPosition =
  solution_interfaces::msg::RobotPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_POSITION__STRUCT_HPP_
