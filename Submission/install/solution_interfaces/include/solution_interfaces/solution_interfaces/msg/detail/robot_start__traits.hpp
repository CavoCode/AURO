// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from solution_interfaces:msg/RobotStart.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__TRAITS_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "solution_interfaces/msg/detail/robot_start__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace solution_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStart & msg,
  std::ostream & out)
{
  out << "{";
  // member: start_assessment
  {
    out << "start_assessment: ";
    rosidl_generator_traits::value_to_yaml(msg.start_assessment, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStart & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start_assessment
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_assessment: ";
    rosidl_generator_traits::value_to_yaml(msg.start_assessment, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStart & msg, bool use_flow_style = false)
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
  const solution_interfaces::msg::RobotStart & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::msg::RobotStart & msg)
{
  return solution_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::msg::RobotStart>()
{
  return "solution_interfaces::msg::RobotStart";
}

template<>
inline const char * name<solution_interfaces::msg::RobotStart>()
{
  return "solution_interfaces/msg/RobotStart";
}

template<>
struct has_fixed_size<solution_interfaces::msg::RobotStart>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<solution_interfaces::msg::RobotStart>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<solution_interfaces::msg::RobotStart>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__TRAITS_HPP_
