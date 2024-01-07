// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:msg/ItemAssessment.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__STRUCT_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal_point_stamped'
#include "geometry_msgs/msg/detail/point_stamped__struct.h"
// Member 'goal_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ItemAssessment in the package solution_interfaces.
typedef struct solution_interfaces__msg__ItemAssessment
{
  geometry_msgs__msg__PointStamped goal_point_stamped;
  rosidl_runtime_c__String goal_type;
} solution_interfaces__msg__ItemAssessment;

// Struct for a sequence of solution_interfaces__msg__ItemAssessment.
typedef struct solution_interfaces__msg__ItemAssessment__Sequence
{
  solution_interfaces__msg__ItemAssessment * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__msg__ItemAssessment__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__ITEM_ASSESSMENT__STRUCT_H_
