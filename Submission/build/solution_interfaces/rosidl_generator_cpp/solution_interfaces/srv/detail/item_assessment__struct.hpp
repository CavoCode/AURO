// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from solution_interfaces:srv/ItemAssessment.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__STRUCT_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'items'
#include "assessment_interfaces/msg/detail/item_list__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__solution_interfaces__srv__ItemAssessment_Request __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__srv__ItemAssessment_Request __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ItemAssessment_Request_
{
  using Type = ItemAssessment_Request_<ContainerAllocator>;

  explicit ItemAssessment_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : items(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0;
    }
  }

  explicit ItemAssessment_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : items(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0;
    }
  }

  // field types and members
  using _value_type =
    uint8_t;
  _value_type value;
  using _items_type =
    assessment_interfaces::msg::ItemList_<ContainerAllocator>;
  _items_type items;

  // setters for named parameter idiom
  Type & set__value(
    const uint8_t & _arg)
  {
    this->value = _arg;
    return *this;
  }
  Type & set__items(
    const assessment_interfaces::msg::ItemList_<ContainerAllocator> & _arg)
  {
    this->items = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__srv__ItemAssessment_Request
    std::shared_ptr<solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__srv__ItemAssessment_Request
    std::shared_ptr<solution_interfaces::srv::ItemAssessment_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ItemAssessment_Request_ & other) const
  {
    if (this->value != other.value) {
      return false;
    }
    if (this->items != other.items) {
      return false;
    }
    return true;
  }
  bool operator!=(const ItemAssessment_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ItemAssessment_Request_

// alias to use template instance with default allocator
using ItemAssessment_Request =
  solution_interfaces::srv::ItemAssessment_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace solution_interfaces


// Include directives for member types
// Member 'item'
#include "assessment_interfaces/msg/detail/item__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__solution_interfaces__srv__ItemAssessment_Response __attribute__((deprecated))
#else
# define DEPRECATED__solution_interfaces__srv__ItemAssessment_Response __declspec(deprecated)
#endif

namespace solution_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ItemAssessment_Response_
{
  using Type = ItemAssessment_Response_<ContainerAllocator>;

  explicit ItemAssessment_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : item(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0f;
      this->angle = 0.0f;
    }
  }

  explicit ItemAssessment_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : item(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0f;
      this->angle = 0.0f;
    }
  }

  // field types and members
  using _item_type =
    assessment_interfaces::msg::Item_<ContainerAllocator>;
  _item_type item;
  using _distance_type =
    float;
  _distance_type distance;
  using _angle_type =
    float;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__item(
    const assessment_interfaces::msg::Item_<ContainerAllocator> & _arg)
  {
    this->item = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
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
    solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__solution_interfaces__srv__ItemAssessment_Response
    std::shared_ptr<solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__solution_interfaces__srv__ItemAssessment_Response
    std::shared_ptr<solution_interfaces::srv::ItemAssessment_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ItemAssessment_Response_ & other) const
  {
    if (this->item != other.item) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const ItemAssessment_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ItemAssessment_Response_

// alias to use template instance with default allocator
using ItemAssessment_Response =
  solution_interfaces::srv::ItemAssessment_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace solution_interfaces

namespace solution_interfaces
{

namespace srv
{

struct ItemAssessment
{
  using Request = solution_interfaces::srv::ItemAssessment_Request;
  using Response = solution_interfaces::srv::ItemAssessment_Response;
};

}  // namespace srv

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__STRUCT_HPP_
