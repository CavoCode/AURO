// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from solution_interfaces:msg/RobotStart.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/msg/detail/robot_start__rosidl_typesupport_fastrtps_cpp.hpp"
#include "solution_interfaces/msg/detail/robot_start__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace solution_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
cdr_serialize(
  const solution_interfaces::msg::RobotStart & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: start_assessment
  cdr << (ros_message.start_assessment ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  solution_interfaces::msg::RobotStart & ros_message)
{
  // Member: start_assessment
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.start_assessment = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
get_serialized_size(
  const solution_interfaces::msg::RobotStart & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: start_assessment
  {
    size_t item_size = sizeof(ros_message.start_assessment);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
max_serialized_size_RobotStart(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: start_assessment
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = solution_interfaces::msg::RobotStart;
    is_plain =
      (
      offsetof(DataType, start_assessment) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotStart__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const solution_interfaces::msg::RobotStart *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotStart__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<solution_interfaces::msg::RobotStart *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotStart__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const solution_interfaces::msg::RobotStart *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotStart__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotStart(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotStart__callbacks = {
  "solution_interfaces::msg",
  "RobotStart",
  _RobotStart__cdr_serialize,
  _RobotStart__cdr_deserialize,
  _RobotStart__get_serialized_size,
  _RobotStart__max_serialized_size
};

static rosidl_message_type_support_t _RobotStart__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotStart__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace solution_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_solution_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<solution_interfaces::msg::RobotStart>()
{
  return &solution_interfaces::msg::typesupport_fastrtps_cpp::_RobotStart__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, solution_interfaces, msg, RobotStart)() {
  return &solution_interfaces::msg::typesupport_fastrtps_cpp::_RobotStart__handle;
}

#ifdef __cplusplus
}
#endif
