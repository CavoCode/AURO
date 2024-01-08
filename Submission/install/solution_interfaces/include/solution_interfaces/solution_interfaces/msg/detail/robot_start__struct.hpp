// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:msg/RobotStart.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__STRUCT_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__solution_interfaces__msg__RobotStart __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__msg__RobotStart __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStart_
{
  using Type = RobotStart_<ContainerAllocator>;

  explicit RobotStart_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_assessment = false;
    }
  }

  explicit RobotStart_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_assessment = false;
    }
  }

  // field types and members
  using _start_assessment_type =
    bool;
  _start_assessment_type start_assessment;

  // setters for named parameter idiom
  Type & set__start_assessment(
    const bool & _arg)
  {
    this->start_assessment = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::msg::RobotStart_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::msg::RobotStart_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::msg::RobotStart_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::msg::RobotStart_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::RobotStart_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::RobotStart_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::RobotStart_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::RobotStart_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::msg::RobotStart_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::msg::RobotStart_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__msg__RobotStart
    std::shared_ptr<solution_interfaces::msg::RobotStart_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__msg__RobotStart
    std::shared_ptr<solution_interfaces::msg::RobotStart_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStart_ & other) const
  {
    if (this->start_assessment != other.start_assessment) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStart_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStart_

// alias to use template instance with default allocator
using RobotStart =
  solution_interfaces::msg::RobotStart_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__STRUCT_HPP_
