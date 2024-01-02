// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from solution_interfaces:msg/GoHome.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "solution_interfaces/msg/detail/go_home__struct.h"
#include "solution_interfaces/msg/detail/go_home__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace solution_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _GoHome_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoHome_type_support_ids_t;

static const _GoHome_type_support_ids_t _GoHome_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoHome_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoHome_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoHome_type_support_symbol_names_t _GoHome_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, solution_interfaces, msg, GoHome)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, solution_interfaces, msg, GoHome)),
  }
};

typedef struct _GoHome_type_support_data_t
{
  void * data[2];
} _GoHome_type_support_data_t;

static _GoHome_type_support_data_t _GoHome_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoHome_message_typesupport_map = {
  2,
  "solution_interfaces",
  &_GoHome_message_typesupport_ids.typesupport_identifier[0],
  &_GoHome_message_typesupport_symbol_names.symbol_name[0],
  &_GoHome_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoHome_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoHome_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace solution_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, solution_interfaces, msg, GoHome)() {
  return &::solution_interfaces::msg::rosidl_typesupport_c::GoHome_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
