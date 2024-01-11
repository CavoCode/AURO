// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from solution_interfaces:srv/RandomGoal.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__TRAITS_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "solution_interfaces/srv/detail/random_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace solution_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RandomGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RandomGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RandomGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace solution_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use solution_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const solution_interfaces::srv::RandomGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::srv::RandomGoal_Request & msg)
{
  return solution_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::srv::RandomGoal_Request>()
{
  return "solution_interfaces::srv::RandomGoal_Request";
}

template<>
inline const char * name<solution_interfaces::srv::RandomGoal_Request>()
{
  return "solution_interfaces/srv/RandomGoal_Request";
}

template<>
struct has_fixed_size<solution_interfaces::srv::RandomGoal_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<solution_interfaces::srv::RandomGoal_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<solution_interfaces::srv::RandomGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace solution_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RandomGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: new_x
  {
    out << "new_x: ";
    rosidl_generator_traits::value_to_yaml(msg.new_x, out);
    out << ", ";
  }

  // member: new_y
  {
    out << "new_y: ";
    rosidl_generator_traits::value_to_yaml(msg.new_y, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RandomGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: new_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "new_x: ";
    rosidl_generator_traits::value_to_yaml(msg.new_x, out);
    out << "\n";
  }

  // member: new_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "new_y: ";
    rosidl_generator_traits::value_to_yaml(msg.new_y, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RandomGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace solution_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use solution_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const solution_interfaces::srv::RandomGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::srv::RandomGoal_Response & msg)
{
  return solution_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::srv::RandomGoal_Response>()
{
  return "solution_interfaces::srv::RandomGoal_Response";
}

template<>
inline const char * name<solution_interfaces::srv::RandomGoal_Response>()
{
  return "solution_interfaces/srv/RandomGoal_Response";
}

template<>
struct has_fixed_size<solution_interfaces::srv::RandomGoal_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<solution_interfaces::srv::RandomGoal_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<solution_interfaces::srv::RandomGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<solution_interfaces::srv::RandomGoal>()
{
  return "solution_interfaces::srv::RandomGoal";
}

template<>
inline const char * name<solution_interfaces::srv::RandomGoal>()
{
  return "solution_interfaces/srv/RandomGoal";
}

template<>
struct has_fixed_size<solution_interfaces::srv::RandomGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<solution_interfaces::srv::RandomGoal_Request>::value &&
    has_fixed_size<solution_interfaces::srv::RandomGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<solution_interfaces::srv::RandomGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<solution_interfaces::srv::RandomGoal_Request>::value &&
    has_bounded_size<solution_interfaces::srv::RandomGoal_Response>::value
  >
{
};

template<>
struct is_service<solution_interfaces::srv::RandomGoal>
  : std::true_type
{
};

template<>
struct is_service_request<solution_interfaces::srv::RandomGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<solution_interfaces::srv::RandomGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__TRAITS_HPP_
