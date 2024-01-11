// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:srv/RandomGoal.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__STRUCT_H_
#define SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RandomGoal in the package solution_interfaces.
typedef struct solution_interfaces__srv__RandomGoal_Request
{
  float x;
  float y;
} solution_interfaces__srv__RandomGoal_Request;

// Struct for a sequence of solution_interfaces__srv__RandomGoal_Request.
typedef struct solution_interfaces__srv__RandomGoal_Request__Sequence
{
  solution_interfaces__srv__RandomGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__srv__RandomGoal_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/RandomGoal in the package solution_interfaces.
typedef struct solution_interfaces__srv__RandomGoal_Response
{
  float new_x;
  float new_y;
  float angle;
} solution_interfaces__srv__RandomGoal_Response;

// Struct for a sequence of solution_interfaces__srv__RandomGoal_Response.
typedef struct solution_interfaces__srv__RandomGoal_Response__Sequence
{
  solution_interfaces__srv__RandomGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__srv__RandomGoal_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__STRUCT_H_
