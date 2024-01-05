// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:msg/StringWithPose.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__STRING_WITH_POSE__BUILDER_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__STRING_WITH_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/msg/detail/string_with_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace msg
{

namespace builder
{

class Init_StringWithPose_pose
{
public:
  explicit Init_StringWithPose_pose(::solution_interfaces::msg::StringWithPose & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::msg::StringWithPose pose(::solution_interfaces::msg::StringWithPose::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::msg::StringWithPose msg_;
};

class Init_StringWithPose_text
{
public:
  Init_StringWithPose_text()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StringWithPose_pose text(::solution_interfaces::msg::StringWithPose::_text_type arg)
  {
    msg_.text = std::move(arg);
    return Init_StringWithPose_pose(msg_);
  }

private:
  ::solution_interfaces::msg::StringWithPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::msg::StringWithPose>()
{
  return solution_interfaces::msg::builder::Init_StringWithPose_text();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__STRING_WITH_POSE__BUILDER_HPP_
