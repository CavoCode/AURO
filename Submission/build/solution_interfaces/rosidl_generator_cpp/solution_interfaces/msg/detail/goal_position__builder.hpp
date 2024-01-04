// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/GoalPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/goal_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_GoalPosition_goal_type
{
public:
  explicit Init_GoalPosition_goal_type(::solution_interfaces::msg::GoalPosition & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::GoalPosition goal_type(::solution_interfaces::msg::GoalPosition::_goal_type_type arg)
  {
    msg_.goal_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::GoalPosition msg_;
};

class Init_GoalPosition_pose_stamped
{
public:
  Init_GoalPosition_pose_stamped()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoalPosition_goal_type pose_stamped(::solution_interfaces::msg::GoalPosition::_pose_stamped_type arg)
  {
    msg_.pose_stamped = std::move(arg);
    return Init_GoalPosition_goal_type(msg_);
  }

private:
  ::solution_interfaces::msg::GoalPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::GoalPosition>()
{
  return solution_interfaces::msg::builder::Init_GoalPosition_pose_stamped();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__BUILDER_HPP_
