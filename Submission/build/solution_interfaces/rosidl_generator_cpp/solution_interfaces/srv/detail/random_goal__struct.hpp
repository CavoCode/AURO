// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:srv/RandomGoal.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__STRUCT_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__solution_interfaces__srv__RandomGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__srv__RandomGoal_Request __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RandomGoal_Request_
{
  using Type = RandomGoal_Request_<ContainerAllocator>;

  explicit RandomGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  explicit RandomGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__srv__RandomGoal_Request
    std::shared_ptr<solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__srv__RandomGoal_Request
    std::shared_ptr<solution_interfaces::srv::RandomGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RandomGoal_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const RandomGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RandomGoal_Request_

// alias to use template instance with default allocator
using RandomGoal_Request =
  solution_interfaces::srv::RandomGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace solution_interfaces


#ifndef _WIN32
# define DEPRECATED__solution_interfaces__srv__RandomGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__srv__RandomGoal_Response __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RandomGoal_Response_
{
  using Type = RandomGoal_Response_<ContainerAllocator>;

  explicit RandomGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_x = 0.0f;
      this->new_y = 0.0f;
      this->angle = 0.0f;
    }
  }

  explicit RandomGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_x = 0.0f;
      this->new_y = 0.0f;
      this->angle = 0.0f;
    }
  }

  // field types and members
  using _new_x_type =
    float;
  _new_x_type new_x;
  using _new_y_type =
    float;
  _new_y_type new_y;
  using _angle_type =
    float;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__new_x(
    const float & _arg)
  {
    this->new_x = _arg;
    return *this;
  }
  Type & set__new_y(
    const float & _arg)
  {
    this->new_y = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__srv__RandomGoal_Response
    std::shared_ptr<solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__srv__RandomGoal_Response
    std::shared_ptr<solution_interfaces::srv::RandomGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RandomGoal_Response_ & other) const
  {
    if (this->new_x != other.new_x) {
      return false;
    }
    if (this->new_y != other.new_y) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const RandomGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RandomGoal_Response_

// alias to use template instance with default allocator
using RandomGoal_Response =
  solution_interfaces::srv::RandomGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace solution_interfaces

namespace solution_interfaces
{

namespace srv
{

struct RandomGoal
{
  using Request = solution_interfaces::srv::RandomGoal_Request;
  using Response = solution_interfaces::srv::RandomGoal_Response;
};

}  // namespace srv

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__STRUCT_HPP_
