// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from solution_interfaces:msg/LocateHome.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__TRAITS_HPP_
#define SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "solution_interfaces/msg/detail/locate_home__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace solution_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LocateHome & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: locate_home
  {
    out << "locate_home: ";
    rosidl_generator_traits::value_to_yaml(msg.locate_home, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LocateHome & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: locate_home
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "locate_home: ";
    rosidl_generator_traits::value_to_yaml(msg.locate_home, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LocateHome & msg, bool use_flow_style = false)
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
  const solution_interfaces::msg::LocateHome & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::msg::LocateHome & msg)
{
  return solution_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::msg::LocateHome>()
{
  return "solution_interfaces::msg::LocateHome";
}

template<>
inline const char * name<solution_interfaces::msg::LocateHome>()
{
  return "solution_interfaces/msg/LocateHome";
}

template<>
struct has_fixed_size<solution_interfaces::msg::LocateHome>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<solution_interfaces::msg::LocateHome>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<solution_interfaces::msg::LocateHome>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__TRAITS_HPP_
