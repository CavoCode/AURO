// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from solution_interfaces:srv/ItemAssessment.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__TRAITS_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "solution_interfaces/srv/detail/item_assessment__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'items'
#include "assessment_interfaces/msg/detail/item_list__traits.hpp"

namespace solution_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ItemAssessment_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << ", ";
  }

  // member: items
  {
    out << "items: ";
    to_flow_style_yaml(msg.items, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ItemAssessment_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }

  // member: items
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "items:\n";
    to_block_style_yaml(msg.items, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ItemAssessment_Request & msg, bool use_flow_style = false)
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
  const solution_interfaces::srv::ItemAssessment_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::srv::ItemAssessment_Request & msg)
{
  return solution_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::srv::ItemAssessment_Request>()
{
  return "solution_interfaces::srv::ItemAssessment_Request";
}

template<>
inline const char * name<solution_interfaces::srv::ItemAssessment_Request>()
{
  return "solution_interfaces/srv/ItemAssessment_Request";
}

template<>
struct has_fixed_size<solution_interfaces::srv::ItemAssessment_Request>
  : std::integral_constant<bool, has_fixed_size<assessment_interfaces::msg::ItemList>::value> {};

template<>
struct has_bounded_size<solution_interfaces::srv::ItemAssessment_Request>
  : std::integral_constant<bool, has_bounded_size<assessment_interfaces::msg::ItemList>::value> {};

template<>
struct is_message<solution_interfaces::srv::ItemAssessment_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'item'
#include "assessment_interfaces/msg/detail/item__traits.hpp"

namespace solution_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ItemAssessment_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: item
  {
    out << "item: ";
    to_flow_style_yaml(msg.item, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
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
  const ItemAssessment_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: item
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "item:\n";
    to_block_style_yaml(msg.item, out, indentation + 2);
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
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

inline std::string to_yaml(const ItemAssessment_Response & msg, bool use_flow_style = false)
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
  const solution_interfaces::srv::ItemAssessment_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  solution_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use solution_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const solution_interfaces::srv::ItemAssessment_Response & msg)
{
  return solution_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<solution_interfaces::srv::ItemAssessment_Response>()
{
  return "solution_interfaces::srv::ItemAssessment_Response";
}

template<>
inline const char * name<solution_interfaces::srv::ItemAssessment_Response>()
{
  return "solution_interfaces/srv/ItemAssessment_Response";
}

template<>
struct has_fixed_size<solution_interfaces::srv::ItemAssessment_Response>
  : std::integral_constant<bool, has_fixed_size<assessment_interfaces::msg::Item>::value> {};

template<>
struct has_bounded_size<solution_interfaces::srv::ItemAssessment_Response>
  : std::integral_constant<bool, has_bounded_size<assessment_interfaces::msg::Item>::value> {};

template<>
struct is_message<solution_interfaces::srv::ItemAssessment_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<solution_interfaces::srv::ItemAssessment>()
{
  return "solution_interfaces::srv::ItemAssessment";
}

template<>
inline const char * name<solution_interfaces::srv::ItemAssessment>()
{
  return "solution_interfaces/srv/ItemAssessment";
}

template<>
struct has_fixed_size<solution_interfaces::srv::ItemAssessment>
  : std::integral_constant<
    bool,
    has_fixed_size<solution_interfaces::srv::ItemAssessment_Request>::value &&
    has_fixed_size<solution_interfaces::srv::ItemAssessment_Response>::value
  >
{
};

template<>
struct has_bounded_size<solution_interfaces::srv::ItemAssessment>
  : std::integral_constant<
    bool,
    has_bounded_size<solution_interfaces::srv::ItemAssessment_Request>::value &&
    has_bounded_size<solution_interfaces::srv::ItemAssessment_Response>::value
  >
{
};

template<>
struct is_service<solution_interfaces::srv::ItemAssessment>
  : std::true_type
{
};

template<>
struct is_service_request<solution_interfaces::srv::ItemAssessment_Request>
  : std::true_type
{
};

template<>
struct is_service_response<solution_interfaces::srv::ItemAssessment_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__TRAITS_HPP_
