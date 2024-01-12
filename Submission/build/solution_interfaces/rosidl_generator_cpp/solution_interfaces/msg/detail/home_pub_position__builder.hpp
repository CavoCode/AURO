// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/HomePubPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__HOME_PUB_POSITION__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__HOME_PUB_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/home_pub_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_HomePubPosition_angle
{
public:
  explicit Init_HomePubPosition_angle(::solution_interfaces::msg::HomePubPosition & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::HomePubPosition angle(::solution_interfaces::msg::HomePubPosition::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::HomePubPosition msg_;
};

class Init_HomePubPosition_point
{
public:
  Init_HomePubPosition_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HomePubPosition_angle point(::solution_interfaces::msg::HomePubPosition::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_HomePubPosition_angle(msg_);
  }

private:
  ::solution_interfaces::msg::HomePubPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::HomePubPosition>()
{
  return solution_interfaces::msg::builder::Init_HomePubPosition_point();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__HOME_PUB_POSITION__BUILDER_HPP_
