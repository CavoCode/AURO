// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from solution_interfaces:msg/RobotPosition.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/msg/detail/robot_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
solution_interfaces__msg__RobotPosition__init(solution_interfaces__msg__RobotPosition * msg)
{
  if (!msg) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    solution_interfaces__msg__RobotPosition__fini(msg);
    return false;
  }
  return true;
}

void
solution_interfaces__msg__RobotPosition__fini(solution_interfaces__msg__RobotPosition * msg)
{
  if (!msg) {
    return;
  }
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
}

bool
solution_interfaces__msg__RobotPosition__are_equal(const solution_interfaces__msg__RobotPosition * lhs, const solution_interfaces__msg__RobotPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
solution_interfaces__msg__RobotPosition__copy(
  const solution_interfaces__msg__RobotPosition * input,
  solution_interfaces__msg__RobotPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

solution_interfaces__msg__RobotPosition *
solution_interfaces__msg__RobotPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__RobotPosition * msg = (solution_interfaces__msg__RobotPosition *)allocator.allocate(sizeof(solution_interfaces__msg__RobotPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(solution_interfaces__msg__RobotPosition));
  bool success = solution_interfaces__msg__RobotPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
solution_interfaces__msg__RobotPosition__destroy(solution_interfaces__msg__RobotPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    solution_interfaces__msg__RobotPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
solution_interfaces__msg__RobotPosition__Sequence__init(solution_interfaces__msg__RobotPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__RobotPosition * data = NULL;

  if (size) {
    data = (solution_interfaces__msg__RobotPosition *)allocator.zero_allocate(size, sizeof(solution_interfaces__msg__RobotPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = solution_interfaces__msg__RobotPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        solution_interfaces__msg__RobotPosition__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
solution_interfaces__msg__RobotPosition__Sequence__fini(solution_interfaces__msg__RobotPosition__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      solution_interfaces__msg__RobotPosition__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

solution_interfaces__msg__RobotPosition__Sequence *
solution_interfaces__msg__RobotPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__RobotPosition__Sequence * array = (solution_interfaces__msg__RobotPosition__Sequence *)allocator.allocate(sizeof(solution_interfaces__msg__RobotPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = solution_interfaces__msg__RobotPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
solution_interfaces__msg__RobotPosition__Sequence__destroy(solution_interfaces__msg__RobotPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    solution_interfaces__msg__RobotPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
solution_interfaces__msg__RobotPosition__Sequence__are_equal(const solution_interfaces__msg__RobotPosition__Sequence * lhs, const solution_interfaces__msg__RobotPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!solution_interfaces__msg__RobotPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
solution_interfaces__msg__RobotPosition__Sequence__copy(
  const solution_interfaces__msg__RobotPosition__Sequence * input,
  solution_interfaces__msg__RobotPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(solution_interfaces__msg__RobotPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    solution_interfaces__msg__RobotPosition * data =
      (solution_interfaces__msg__RobotPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!solution_interfaces__msg__RobotPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          solution_interfaces__msg__RobotPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!solution_interfaces__msg__RobotPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
