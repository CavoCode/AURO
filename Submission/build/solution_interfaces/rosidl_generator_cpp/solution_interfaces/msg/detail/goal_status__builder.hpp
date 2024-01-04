// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/GoalStatus.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__GOAL_STATUS__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__GOAL_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/goal_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_GoalStatus_goal_type
{
public:
  explicit Init_GoalStatus_goal_type(::solution_interfaces::msg::GoalStatus & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::GoalStatus goal_type(::solution_interfaces::msg::GoalStatus::_goal_type_type arg)
  {
    msg_.goal_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::GoalStatus msg_;
};

class Init_GoalStatus_status
{
public:
  Init_GoalStatus_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoalStatus_goal_type status(::solution_interfaces::msg::GoalStatus::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GoalStatus_goal_type(msg_);
  }

private:
  ::solution_interfaces::msg::GoalStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::GoalStatus>()
{
  return solution_interfaces::msg::builder::Init_GoalStatus_status();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__GOAL_STATUS__BUILDER_HPP_
