// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:msg/ItemAssessment.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__STRUCT_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'goal_point_stamped'
#include "geometry_msgs/msg/detail/point_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__solution_interfaces__msg__ItemAssessment __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__msg__ItemAssessment __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ItemAssessment_
{
  using Type = ItemAssessment_<ContainerAllocator>;

  explicit ItemAssessment_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_point_stamped(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->goal_type = "";
      this->goal_angle = 0.0f;
    }
  }

  explicit ItemAssessment_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_point_stamped(_alloc, _init),
    goal_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->goal_type = "";
      this->goal_angle = 0.0f;
    }
  }

  // field types and members
  using _goal_point_stamped_type =
    geometry_msgs::msg::PointStamped_<ContainerAllocator>;
  _goal_point_stamped_type goal_point_stamped;
  using _goal_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _goal_type_type goal_type;
  using _goal_angle_type =
    float;
  _goal_angle_type goal_angle;

  // setters for named parameter idiom
  Type & set__goal_point_stamped(
    const geometry_msgs::msg::PointStamped_<ContainerAllocator> & _arg)
  {
    this->goal_point_stamped = _arg;
    return *this;
  }
  Type & set__goal_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->goal_type = _arg;
    return *this;
  }
  Type & set__goal_angle(
    const float & _arg)
  {
    this->goal_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::msg::ItemAssessment_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::msg::ItemAssessment_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::msg::ItemAssessment_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::msg::ItemAssessment_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::ItemAssessment_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::ItemAssessment_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::msg::ItemAssessment_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::msg::ItemAssessment_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::msg::ItemAssessment_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::msg::ItemAssessment_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__msg__ItemAssessment
    std::shared_ptr<solution_interfaces::msg::ItemAssessment_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__msg__ItemAssessment
    std::shared_ptr<solution_interfaces::msg::ItemAssessment_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ItemAssessment_ & other) const
  {
    if (this->goal_point_stamped != other.goal_point_stamped) {
      return false;
    }
    if (this->goal_type != other.goal_type) {
      return false;
    }
    if (this->goal_angle != other.goal_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const ItemAssessment_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ItemAssessment_

// alias to use template instance with default allocator
using ItemAssessment =
  solution_interfaces::msg::ItemAssessment_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__STRUCT_HPP_
