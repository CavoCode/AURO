// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/RobotStart.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RobotStart in the package solution_interfaces.
typedef struct solution_interfaces__msg__RobotStart
{
  bool start_assessment;
} solution_interfaces__msg__RobotStart;

// Struct for a sequence of solution_interfaces__msg__RobotStart.
typedef struct solution_interfaces__msg__RobotStart__Sequence
{
  solution_interfaces__msg__RobotStart * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__RobotStart__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ROBOT_START__STRUCT_H_
