// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/ItemAssessment.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/item_assessment__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_ItemAssessment_goal_type
{
public:
  explicit Init_ItemAssessment_goal_type(::solution_interfaces::msg::ItemAssessment & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::ItemAssessment goal_type(::solution_interfaces::msg::ItemAssessment::_goal_type_type arg)
  {
    msg_.goal_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::ItemAssessment msg_;
};

class Init_ItemAssessment_goal_point_stamped
{
public:
  Init_ItemAssessment_goal_point_stamped()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ItemAssessment_goal_type goal_point_stamped(::solution_interfaces::msg::ItemAssessment::_goal_point_stamped_type arg)
  {
    msg_.goal_point_stamped = std::move(arg);
    return Init_ItemAssessment_goal_type(msg_);
  }

private:
  ::solution_interfaces::msg::ItemAssessment msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::ItemAssessment>()
{
  return solution_interfaces::msg::builder::Init_ItemAssessment_goal_point_stamped();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__BUILDER_HPP_
