// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from assessment_interfaces:msg/HomeZone.idl
// generated code does not contain a copyright notice

#ifndef ASSESSMENT_INTERFACES__MSG__DETAIL__HOME_ZONE__STRUCT_H_
#define ASSESSMENT_INTERFACES__MSG__DETAIL__HOME_ZONE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/HomeZone in the package assessment_interfaces.
typedef struct assessment_interfaces__msg__HomeZone
{
  bool visible;
  int16_t x;
  int16_t y;
  float size;
} assessment_interfaces__msg__HomeZone;

// Struct for a sequence of assessment_interfaces__msg__HomeZone.
typedef struct assessment_interfaces__msg__HomeZone__Sequence
{
  assessment_interfaces__msg__HomeZone * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} assessment_interfaces__msg__HomeZone__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ASSESSMENT_INTERFACES__MSG__DETAIL__HOME_ZONE__STRUCT_H_
