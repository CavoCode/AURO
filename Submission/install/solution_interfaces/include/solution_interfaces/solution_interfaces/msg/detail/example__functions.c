// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from solution_interfaces:msg/Example.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/msg/detail/example__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `point`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
solution_interfaces__msg__Example__init(solution_interfaces__msg__Example * msg)
{
  if (!msg) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__init(&msg->point)) {
    solution_interfaces__msg__Example__fini(msg);
    return false;
  }
  return true;
}

void
solution_interfaces__msg__Example__fini(solution_interfaces__msg__Example * msg)
{
  if (!msg) {
    return;
  }
  // point
  geometry_msgs__msg__Point__fini(&msg->point);
}

bool
solution_interfaces__msg__Example__are_equal(const solution_interfaces__msg__Example * lhs, const solution_interfaces__msg__Example * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  return true;
}

bool
solution_interfaces__msg__Example__copy(
  const solution_interfaces__msg__Example * input,
  solution_interfaces__msg__Example * output)
{
  if (!input || !output) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  return true;
}

solution_interfaces__msg__Example *
solution_interfaces__msg__Example__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__Example * msg = (solution_interfaces__msg__Example *)allocator.allocate(sizeof(solution_interfaces__msg__Example), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(solution_interfaces__msg__Example));
  bool success = solution_interfaces__msg__Example__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
solution_interfaces__msg__Example__destroy(solution_interfaces__msg__Example * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    solution_interfaces__msg__Example__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
solution_interfaces__msg__Example__Sequence__init(solution_interfaces__msg__Example__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__Example * data = NULL;

  if (size) {
    data = (solution_interfaces__msg__Example *)allocator.zero_allocate(size, sizeof(solution_interfaces__msg__Example), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = solution_interfaces__msg__Example__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        solution_interfaces__msg__Example__fini(&data[i - 1]);
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
solution_interfaces__msg__Example__Sequence__fini(solution_interfaces__msg__Example__Sequence * array)
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
      solution_interfaces__msg__Example__fini(&array->data[i]);
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

solution_interfaces__msg__Example__Sequence *
solution_interfaces__msg__Example__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__msg__Example__Sequence * array = (solution_interfaces__msg__Example__Sequence *)allocator.allocate(sizeof(solution_interfaces__msg__Example__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = solution_interfaces__msg__Example__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
solution_interfaces__msg__Example__Sequence__destroy(solution_interfaces__msg__Example__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    solution_interfaces__msg__Example__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
solution_interfaces__msg__Example__Sequence__are_equal(const solution_interfaces__msg__Example__Sequence * lhs, const solution_interfaces__msg__Example__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!solution_interfaces__msg__Example__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
solution_interfaces__msg__Example__Sequence__copy(
  const solution_interfaces__msg__Example__Sequence * input,
  solution_interfaces__msg__Example__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(solution_interfaces__msg__Example);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    solution_interfaces__msg__Example * data =
      (solution_interfaces__msg__Example *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!solution_interfaces__msg__Example__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          solution_interfaces__msg__Example__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!solution_interfaces__msg__Example__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
