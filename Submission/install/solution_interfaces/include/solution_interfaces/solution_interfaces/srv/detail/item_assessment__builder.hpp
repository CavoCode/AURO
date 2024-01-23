// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:srv/ItemAssessment.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__BUILDER_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/srv/detail/item_assessment__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace srv
{

namespace builder
{

class Init_ItemAssessment_Request_items
{
public:
  explicit Init_ItemAssessment_Request_items(::solution_interfaces::srv::ItemAssessment_Request & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::srv::ItemAssessment_Request items(::solution_interfaces::srv::ItemAssessment_Request::_items_type arg)
  {
    msg_.items = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::srv::ItemAssessment_Request msg_;
};

class Init_ItemAssessment_Request_value
{
public:
  Init_ItemAssessment_Request_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ItemAssessment_Request_items value(::solution_interfaces::srv::ItemAssessment_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_ItemAssessment_Request_items(msg_);
  }

private:
  ::solution_interfaces::srv::ItemAssessment_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::srv::ItemAssessment_Request>()
{
  return solution_interfaces::srv::builder::Init_ItemAssessment_Request_value();
}

}  // namespace solution_interfaces


namespace solution_interfaces
{

namespace srv
{

namespace builder
{

class Init_ItemAssessment_Response_distance
{
public:
  explicit Init_ItemAssessment_Response_distance(::solution_interfaces::srv::ItemAssessment_Response & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::srv::ItemAssessment_Response distance(::solution_interfaces::srv::ItemAssessment_Response::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::srv::ItemAssessment_Response msg_;
};

class Init_ItemAssessment_Response_item
{
public:
  Init_ItemAssessment_Response_item()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ItemAssessment_Response_distance item(::solution_interfaces::srv::ItemAssessment_Response::_item_type arg)
  {
    msg_.item = std::move(arg);
    return Init_ItemAssessment_Response_distance(msg_);
  }

private:
  ::solution_interfaces::srv::ItemAssessment_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::srv::ItemAssessment_Response>()
{
  return solution_interfaces::srv::builder::Init_ItemAssessment_Response_item();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__BUILDER_HPP_
