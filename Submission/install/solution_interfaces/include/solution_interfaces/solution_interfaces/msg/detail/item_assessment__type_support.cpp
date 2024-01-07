// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from solution_interfaces:msg/ItemAssessment.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "solution_interfaces/msg/detail/item_assessment__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace solution_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ItemAssessment_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) solution_interfaces::msg::ItemAssessment(_init);
}

void ItemAssessment_fini_function(void * message_memory)
{
  auto typed_message = static_cast<solution_interfaces::msg::ItemAssessment *>(message_memory);
  typed_message->~ItemAssessment();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ItemAssessment_message_member_array[2] = {
  {
    "goal_point_stamped",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PointStamped>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::ItemAssessment, goal_point_stamped),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "goal_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::ItemAssessment, goal_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ItemAssessment_message_members = {
  "solution_interfaces::msg",  // message namespace
  "ItemAssessment",  // message name
  2,  // number of fields
  sizeof(solution_interfaces::msg::ItemAssessment),
  ItemAssessment_message_member_array,  // message members
  ItemAssessment_init_function,  // function to initialize message memory (memory has to be allocated)
  ItemAssessment_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ItemAssessment_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ItemAssessment_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace solution_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<solution_interfaces::msg::ItemAssessment>()
{
  return &::solution_interfaces::msg::rosidl_typesupport_introspection_cpp::ItemAssessment_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, solution_interfaces, msg, ItemAssessment)() {
  return &::solution_interfaces::msg::rosidl_typesupport_introspection_cpp::ItemAssessment_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
