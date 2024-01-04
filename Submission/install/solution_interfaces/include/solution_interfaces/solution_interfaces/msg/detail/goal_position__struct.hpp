// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:msg/GoalPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__STRUCT_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose_stamped'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__solution_interfaces__msg__GoalPosition __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__msg__GoalPosition __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GoalPosition_
{
  using Type = GoalPosition_<ContainerAllocator>;

  explicit GoalPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_stamped(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->goal_type = "";
    }
  }

  explicit GoalPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_stamped(_alloc, _init),
    goal_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->goal_type = "";
    }
  }

  // field types and members
  using _pose_stamped_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_stamped_type pose_stamped;
  using _goal_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _goal_type_type goal_type;

  // setters for named parameter idiom
  Type & set__pose_stamped(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose_stamped = _arg;
    return *this;
  }
  Type & set__goal_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->goal_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::msg::GoalPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::msg::GoalPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::msg::GoalPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::msg::GoalPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::GoalPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::GoalPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::GoalPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::GoalPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::msg::GoalPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::msg::GoalPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__msg__GoalPosition
    std::shared_ptr<solution_interfaces::msg::GoalPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__msg__GoalPosition
    std::shared_ptr<solution_interfaces::msg::GoalPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoalPosition_ & other) const
  {
    if (this->pose_stamped != other.pose_stamped) {
      return false;
    }
    if (this->goal_type != other.goal_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoalPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoalPosition_

// alias to use template instance with default allocator
using GoalPosition =
  solution_interfaces::msg::GoalPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__STRUCT_HPP_
