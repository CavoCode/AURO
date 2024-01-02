// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/GoHome.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__GO_HOME__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__GO_HOME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/go_home__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_GoHome_go_home_trigger
{
public:
  explicit Init_GoHome_go_home_trigger(::solution_interfaces::msg::GoHome & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::GoHome go_home_trigger(::solution_interfaces::msg::GoHome::_go_home_trigger_type arg)
  {
    msg_.go_home_trigger = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::GoHome msg_;
};

class Init_GoHome_header
{
public:
  Init_GoHome_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoHome_go_home_trigger header(::solution_interfaces::msg::GoHome::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GoHome_go_home_trigger(msg_);
  }

private:
  ::solution_interfaces::msg::GoHome msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::GoHome>()
{
  return solution_interfaces::msg::builder::Init_GoHome_header();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__GO_HOME__BUILDER_HPP_
