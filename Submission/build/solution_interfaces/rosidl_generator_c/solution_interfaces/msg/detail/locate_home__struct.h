// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/LocateHome.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/LocateHome in the package solution_interfaces.
typedef struct solution_interfaces__msg__LocateHome
{
  std_msgs__msg__Header header;
  bool locate_home;
} solution_interfaces__msg__LocateHome;

// Struct for a sequence of solution_interfaces__msg__LocateHome.
typedef struct solution_interfaces__msg__LocateHome__Sequence
{
  solution_interfaces__msg__LocateHome * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__LocateHome__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__LOCATE_HOME__STRUCT_H_
