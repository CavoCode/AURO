// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from assessment_interfaces:msg/HomeZone.idl
// generated code does not contain a copyright notice

#ifndef ASSESSMENT_INTERFACES__MSG__DETAIL__HOME_ZONE__BUILDER_HPP_
#define ASSESSMENT_INTERFACES__MSG__DETAIL__HOME_ZONE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "assessment_interfaces/msg/detail/home_zone__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace assessment_interfaces
{

namespace msg
{

namespace builder
{

class Init_HomeZone_size
{
public:
  explicit Init_HomeZone_size(::assessment_interfaces::msg::HomeZone & msg)
  : msg_(msg)
  {}
  ::assessment_interfaces::msg::HomeZone size(::assessment_interfaces::msg::HomeZone::_size_type arg)
  {
    msg_.size = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assessment_interfaces::msg::HomeZone msg_;
};

class Init_HomeZone_y
{
public:
  explicit Init_HomeZone_y(::assessment_interfaces::msg::HomeZone & msg)
  : msg_(msg)
  {}
  Init_HomeZone_size y(::assessment_interfaces::msg::HomeZone::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_HomeZone_size(msg_);
  }

private:
  ::assessment_interfaces::msg::HomeZone msg_;
};

class Init_HomeZone_x
{
public:
  explicit Init_HomeZone_x(::assessment_interfaces::msg::HomeZone & msg)
  : msg_(msg)
  {}
  Init_HomeZone_y x(::assessment_interfaces::msg::HomeZone::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_HomeZone_y(msg_);
  }

private:
  ::assessment_interfaces::msg::HomeZone msg_;
};

class Init_HomeZone_visible
{
public:
  Init_HomeZone_visible()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HomeZone_x visible(::assessment_interfaces::msg::HomeZone::_visible_type arg)
  {
    msg_.visible = std::move(arg);
    return Init_HomeZone_x(msg_);
  }

private:
  ::assessment_interfaces::msg::HomeZone msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::assessment_interfaces::msg::HomeZone>()
{
  return assessment_interfaces::msg::builder::Init_HomeZone_visible();
}

}  // namespace assessment_interfaces

#endif  // ASSESSMENT_INTERFACES__MSG__DETAIL__HOME_ZONE__BUILDER_HPP_
