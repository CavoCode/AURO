// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/StringWithPose.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__STRING_WITH_POSE__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__STRING_WITH_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'text'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/StringWithPose in the package solution_interfaces.
typedef struct solution_interfaces__msg__StringWithPose
{
  rosidl_runtime_c__String text;
  geometry_msgs__msg__Pose pose;
} solution_interfaces__msg__StringWithPose;

// Struct for a sequence of solution_interfaces__msg__StringWithPose.
typedef struct solution_interfaces__msg__StringWithPose__Sequence
{
  solution_interfaces__msg__StringWithPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__StringWithPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__STRING_WITH_POSE__STRUCT_H_
