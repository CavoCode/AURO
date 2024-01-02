// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:msg/GoHome.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__GO_HOME__STRUCT_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__GO_HOME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__solution_interfaces__msg__GoHome __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__msg__GoHome __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GoHome_
{
  using Type = GoHome_<ContainerAllocator>;

  explicit GoHome_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->go_home_trigger = false;
    }
  }

  explicit GoHome_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->go_home_trigger = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _go_home_trigger_type =
    bool;
  _go_home_trigger_type go_home_trigger;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__go_home_trigger(
    const bool & _arg)
  {
    this->go_home_trigger = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::msg::GoHome_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::msg::GoHome_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::msg::GoHome_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::msg::GoHome_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::GoHome_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::GoHome_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::GoHome_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::GoHome_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::msg::GoHome_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::msg::GoHome_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__msg__GoHome
    std::shared_ptr<solution_interfaces::msg::GoHome_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__msg__GoHome
    std::shared_ptr<solution_interfaces::msg::GoHome_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoHome_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->go_home_trigger != other.go_home_trigger) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoHome_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoHome_

// alias to use template instance with default allocator
using GoHome =
  solution_interfaces::msg::GoHome_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__GO_HOME__STRUCT_HPP_
