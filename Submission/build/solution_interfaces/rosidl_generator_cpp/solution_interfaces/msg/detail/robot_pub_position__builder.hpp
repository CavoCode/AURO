// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/RobotPubPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_PUB_POSITION__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_PUB_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/robot_pub_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotPubPosition_pose
{
public:
  Init_RobotPubPosition_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::solution_interfaces::msg::RobotPubPosition pose(::solution_interfaces::msg::RobotPubPosition::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::RobotPubPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::RobotPubPosition>()
{
  return solution_interfaces::msg::builder::Init_RobotPubPosition_pose();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_PUB_POSITION__BUILDER_HPP_
