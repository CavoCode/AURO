// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/GoalPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose_stamped'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'goal_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GoalPosition in the package solution_interfaces.
typedef struct solution_interfaces__msg__GoalPosition
{
  geometry_msgs__msg__PoseStamped pose_stamped;
  rosidl_runtime_c__String goal_type;
} solution_interfaces__msg__GoalPosition;

// Struct for a sequence of solution_interfaces__msg__GoalPosition.
typedef struct solution_interfaces__msg__GoalPosition__Sequence
{
  solution_interfaces__msg__GoalPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__GoalPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__GOAL_POSITION__STRUCT_H_
