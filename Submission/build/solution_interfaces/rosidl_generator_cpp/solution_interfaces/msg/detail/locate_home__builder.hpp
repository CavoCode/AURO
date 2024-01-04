// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/LocateHome.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/locate_home__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_LocateHome_locate_home
{
public:
  explicit Init_LocateHome_locate_home(::solution_interfaces::msg::LocateHome & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::LocateHome locate_home(::solution_interfaces::msg::LocateHome::_locate_home_type arg)
  {
    msg_.locate_home = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::LocateHome msg_;
};

class Init_LocateHome_header
{
public:
  Init_LocateHome_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LocateHome_locate_home header(::solution_interfaces::msg::LocateHome::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LocateHome_locate_home(msg_);
  }

private:
  ::solution_interfaces::msg::LocateHome msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::LocateHome>()
{
  return solution_interfaces::msg::builder::Init_LocateHome_header();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__BUILDER_HPP_
