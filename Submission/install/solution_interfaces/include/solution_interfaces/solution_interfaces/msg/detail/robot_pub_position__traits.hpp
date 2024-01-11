// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from solution_interfaces:msg/RobotPubPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_PUB_POSITION__TRAITS_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_PUB_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "solution_interfaces/msg/detail/robot_pub_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace solution_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotPubPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotPubPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotPubPosition & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace solution_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use solution_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const solution_interfaces::msg::RobotPubPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::msg::RobotPubPosition & msg)
{
  return solution_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::msg::RobotPubPosition>()
{
  return "solution_interfaces::msg::RobotPubPosition";
}

template<>
inline const char * name<solution_interfaces::msg::RobotPubPosition>()
{
  return "solution_interfaces/msg/RobotPubPosition";
}

template<>
struct has_fixed_size<solution_interfaces::msg::RobotPubPosition>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<solution_interfaces::msg::RobotPubPosition>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<solution_interfaces::msg::RobotPubPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_PUB_POSITION__TRAITS_HPP_
