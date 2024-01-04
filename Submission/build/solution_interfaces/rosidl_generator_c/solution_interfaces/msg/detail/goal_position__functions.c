// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from solution_interfaces:msg/GoalPosition.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/msg/detail/goal_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pose_stamped`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `goal_type`
#include "rosidl_runtime_c/string_functions.h"

bool
solution_interfaces__msg__GoalPosition__init(solution_interfaces__msg__GoalPosition * msg)
{
  if (!msg) {
    return false;
  }
  // pose_stamped
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose_stamped)) {
    solution_interfaces__msg__GoalPosition__fini(msg);
    return false;
  }
  // goal_type
  if (!rosidl_runtime_c__String__init(&msg->goal_type)) {
    solution_interfaces__msg__GoalPosition__fini(msg);
    return false;
  }
  return true;
}

void
solution_interfaces__msg__GoalPosition__fini(solution_interfaces__msg__GoalPosition * msg)
{
  if (!msg) {
    return;
  }
  // pose_stamped
  geometry_msgs__msg__PoseStamped__fini(&msg->pose_stamped);
  // goal_type
  rosidl_runtime_c__String__fini(&msg->goal_type);
}

bool
solution_interfaces__msg__GoalPosition__are_equal(const solution_interfaces__msg__GoalPosition * lhs, const solution_interfaces__msg__GoalPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose_stamped
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose_stamped), &(rhs->pose_stamped)))
  {
    return false;
  }
  // goal_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->goal_type), &(rhs->goal_type)))
  {
    return false;
  }
  return true;
}

bool
solution_interfaces__msg__GoalPosition__copy(
  const solution_interfaces__msg__GoalPosition * input,
  solution_interfaces__msg__GoalPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // pose_stamped
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose_stamped), &(output->pose_stamped)))
  {
    return false;
  }
  // goal_type
  if (!rosidl_runtime_c__String__copy(
      &(input->goal_type), &(output->goal_type)))
  {
    return false;
  }
  return true;
}

solution_interfaces__msg__GoalPosition *
solution_interfaces__msg__GoalPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__GoalPosition * msg = (solution_interfaces__msg__GoalPosition *)allocator.allocate(sizeof(solution_interfaces__msg__GoalPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(solution_interfaces__msg__GoalPosition));
  bool success = solution_interfaces__msg__GoalPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
solution_interfaces__msg__GoalPosition__destroy(solution_interfaces__msg__GoalPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    solution_interfaces__msg__GoalPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
solution_interfaces__msg__GoalPosition__Sequence__init(solution_interfaces__msg__GoalPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__GoalPosition * data = NULL;

  if (size) {
    data = (solution_interfaces__msg__GoalPosition *)allocator.zero_allocate(size, sizeof(solution_interfaces__msg__GoalPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = solution_interfaces__msg__GoalPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        solution_interfaces__msg__GoalPosition__fini(&data[i - 1]);
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
solution_interfaces__msg__GoalPosition__Sequence__fini(solution_interfaces__msg__GoalPosition__Sequence * array)
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
      solution_interfaces__msg__GoalPosition__fini(&array->data[i]);
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

solution_interfaces__msg__GoalPosition__Sequence *
solution_interfaces__msg__GoalPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__GoalPosition__Sequence * array = (solution_interfaces__msg__GoalPosition__Sequence *)allocator.allocate(sizeof(solution_interfaces__msg__GoalPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = solution_interfaces__msg__GoalPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
solution_interfaces__msg__GoalPosition__Sequence__destroy(solution_interfaces__msg__GoalPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    solution_interfaces__msg__GoalPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
solution_interfaces__msg__GoalPosition__Sequence__are_equal(const solution_interfaces__msg__GoalPosition__Sequence * lhs, const solution_interfaces__msg__GoalPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!solution_interfaces__msg__GoalPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
solution_interfaces__msg__GoalPosition__Sequence__copy(
  const solution_interfaces__msg__GoalPosition__Sequence * input,
  solution_interfaces__msg__GoalPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(solution_interfaces__msg__GoalPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    solution_interfaces__msg__GoalPosition * data =
      (solution_interfaces__msg__GoalPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!solution_interfaces__msg__GoalPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          solution_interfaces__msg__GoalPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!solution_interfaces__msg__GoalPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
