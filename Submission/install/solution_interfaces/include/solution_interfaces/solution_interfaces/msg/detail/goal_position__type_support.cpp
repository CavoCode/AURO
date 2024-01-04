// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from solution_interfaces:msg/GoalPosition.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "solution_interfaces/msg/detail/goal_position__struct.hpp"
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

void GoalPosition_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) solution_interfaces::msg::GoalPosition(_init);
}

void GoalPosition_fini_function(void * message_memory)
{
  auto typed_message = static_cast<solution_interfaces::msg::GoalPosition *>(message_memory);
  typed_message->~GoalPosition();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GoalPosition_message_member_array[2] = {
  {
    "pose_stamped",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PoseStamped>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(solution_interfaces::msg::GoalPosition, pose_stamped),  // bytes offset in struct
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
    offsetof(solution_interfaces::msg::GoalPosition, goal_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GoalPosition_message_members = {
  "solution_interfaces::msg",  // message namespace
  "GoalPosition",  // message name
  2,  // number of fields
  sizeof(solution_interfaces::msg::GoalPosition),
  GoalPosition_message_member_array,  // message members
  GoalPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  GoalPosition_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GoalPosition_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GoalPosition_message_members,
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
get_message_type_support_handle<solution_interfaces::msg::GoalPosition>()
{
  return &::solution_interfaces::msg::rosidl_typesupport_introspection_cpp::GoalPosition_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, solution_interfaces, msg, GoalPosition)() {
  return &::solution_interfaces::msg::rosidl_typesupport_introspection_cpp::GoalPosition_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
