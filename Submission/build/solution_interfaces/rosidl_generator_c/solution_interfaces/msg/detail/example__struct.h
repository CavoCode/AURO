// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/Example.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__EXAMPLE__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__EXAMPLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Example in the package solution_interfaces.
typedef struct solution_interfaces__msg__Example
{
  geometry_msgs__msg__Point point;
} solution_interfaces__msg__Example;

// Struct for a sequence of solution_interfaces__msg__Example.
typedef struct solution_interfaces__msg__Example__Sequence
{
  solution_interfaces__msg__Example * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__Example__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__EXAMPLE__STRUCT_H_
