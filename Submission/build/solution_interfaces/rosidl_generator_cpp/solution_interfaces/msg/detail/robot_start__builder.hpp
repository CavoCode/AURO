// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/RobotStart.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/robot_start__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotStart_start_assessment
{
public:
  Init_RobotStart_start_assessment()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::solution_interfaces::msg::RobotStart start_assessment(::solution_interfaces::msg::RobotStart::_start_assessment_type arg)
  {
    msg_.start_assessment = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::RobotStart msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::RobotStart>()
{
  return solution_interfaces::msg::builder::Init_RobotStart_start_assessment();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__BUILDER_HPP_
