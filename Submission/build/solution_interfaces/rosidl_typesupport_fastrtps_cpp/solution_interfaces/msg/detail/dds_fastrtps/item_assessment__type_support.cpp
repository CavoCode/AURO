// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from solution_interfaces:msg/ItemAssessment.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/msg/detail/item_assessment__rosidl_typesupport_fastrtps_cpp.hpp"
#include "solution_interfaces/msg/detail/item_assessment__struct.hpp"

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
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::PointStamped &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::PointStamped &);
size_t get_serialized_size(
  const geometry_msgs::msg::PointStamped &,
  size_t current_alignment);
size_t
max_serialized_size_PointStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace solution_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
cdr_serialize(
  const solution_interfaces::msg::ItemAssessment & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: goal_point_stamped
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.goal_point_stamped,
    cdr);
  // Member: goal_type
  cdr << ros_message.goal_type;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  solution_interfaces::msg::ItemAssessment & ros_message)
{
  // Member: goal_point_stamped
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.goal_point_stamped);

  // Member: goal_type
  cdr >> ros_message.goal_type;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
get_serialized_size(
  const solution_interfaces::msg::ItemAssessment & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: goal_point_stamped

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.goal_point_stamped, current_alignment);
  // Member: goal_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.goal_type.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_solution_interfaces
max_serialized_size_ItemAssessment(
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


  // Member: goal_point_stamped
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_PointStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: goal_type
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = solution_interfaces::msg::ItemAssessment;
    is_plain =
      (
      offsetof(DataType, goal_type) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ItemAssessment__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const solution_interfaces::msg::ItemAssessment *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ItemAssessment__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<solution_interfaces::msg::ItemAssessment *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ItemAssessment__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const solution_interfaces::msg::ItemAssessment *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ItemAssessment__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ItemAssessment(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ItemAssessment__callbacks = {
  "solution_interfaces::msg",
  "ItemAssessment",
  _ItemAssessment__cdr_serialize,
  _ItemAssessment__cdr_deserialize,
  _ItemAssessment__get_serialized_size,
  _ItemAssessment__max_serialized_size
};

static rosidl_message_type_support_t _ItemAssessment__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ItemAssessment__callbacks,
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
get_message_type_support_handle<solution_interfaces::msg::ItemAssessment>()
{
  return &solution_interfaces::msg::typesupport_fastrtps_cpp::_ItemAssessment__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, solution_interfaces, msg, ItemAssessment)() {
  return &solution_interfaces::msg::typesupport_fastrtps_cpp::_ItemAssessment__handle;
}

#ifdef __cplusplus
}
#endif
