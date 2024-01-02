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

class Init_GoalStatus_result
{
public:
  Init_GoalStatus_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::solution_interfaces::msg::GoalStatus result(::solution_interfaces::msg::GoalStatus::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
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
  return solution_interfaces::msg::builder::Init_GoalStatus_result();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__GOAL_STATUS__BUILDER_HPP_
