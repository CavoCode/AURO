// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/GoalStatus.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__GOAL_STATUS__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__GOAL_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'status'
// Member 'goal_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GoalStatus in the package solution_interfaces.
typedef struct solution_interfaces__msg__GoalStatus
{
  rosidl_runtime_c__String status;
  rosidl_runtime_c__String goal_type;
} solution_interfaces__msg__GoalStatus;

// Struct for a sequence of solution_interfaces__msg__GoalStatus.
typedef struct solution_interfaces__msg__GoalStatus__Sequence
{
  solution_interfaces__msg__GoalStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__GoalStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__GOAL_STATUS__STRUCT_H_
