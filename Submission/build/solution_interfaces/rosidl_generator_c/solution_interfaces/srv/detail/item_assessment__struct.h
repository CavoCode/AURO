// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from solution_interfaces:srv/ItemAssessment.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__STRUCT_H_
#define SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'items'
#include "assessment_interfaces/msg/detail/item_list__struct.h"

/// Struct defined in srv/ItemAssessment in the package solution_interfaces.
typedef struct solution_interfaces__srv__ItemAssessment_Request
{
  uint8_t value;
  assessment_interfaces__msg__ItemList items;
} solution_interfaces__srv__ItemAssessment_Request;

// Struct for a sequence of solution_interfaces__srv__ItemAssessment_Request.
typedef struct solution_interfaces__srv__ItemAssessment_Request__Sequence
{
  solution_interfaces__srv__ItemAssessment_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__srv__ItemAssessment_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'item'
#include "assessment_interfaces/msg/detail/item__struct.h"

/// Struct defined in srv/ItemAssessment in the package solution_interfaces.
typedef struct solution_interfaces__srv__ItemAssessment_Response
{
  assessment_interfaces__msg__Item item;
  float distance;
} solution_interfaces__srv__ItemAssessment_Response;

// Struct for a sequence of solution_interfaces__srv__ItemAssessment_Response.
typedef struct solution_interfaces__srv__ItemAssessment_Response__Sequence
{
  solution_interfaces__srv__ItemAssessment_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} solution_interfaces__srv__ItemAssessment_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__ITEM_ASSESSMENT__STRUCT_H_
