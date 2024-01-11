// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/RobotPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_POSITION__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/robot_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotPosition_pose
{
public:
  Init_RobotPosition_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::solution_interfaces::msg::RobotPosition pose(::solution_interfaces::msg::RobotPosition::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::RobotPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::RobotPosition>()
{
  return solution_interfaces::msg::builder::Init_RobotPosition_pose();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_POSITION__BUILDER_HPP_
