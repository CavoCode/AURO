// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from assessment_interfaces:msg/HomeZone.idl
// generated code does not contain a copyright notice
#include "assessment_interfaces/msg/detail/home_zone__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
assessment_interfaces__msg__HomeZone__init(assessment_interfaces__msg__HomeZone * msg)
{
  if (!msg) {
    return false;
  }
  // visible
  // x
  // y
  // size
  return true;
}

void
assessment_interfaces__msg__HomeZone__fini(assessment_interfaces__msg__HomeZone * msg)
{
  if (!msg) {
    return;
  }
  // visible
  // x
  // y
  // size
}

bool
assessment_interfaces__msg__HomeZone__are_equal(const assessment_interfaces__msg__HomeZone * lhs, const assessment_interfaces__msg__HomeZone * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // visible
  if (lhs->visible != rhs->visible) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // size
  if (lhs->size != rhs->size) {
    return false;
  }
  return true;
}

bool
assessment_interfaces__msg__HomeZone__copy(
  const assessment_interfaces__msg__HomeZone * input,
  assessment_interfaces__msg__HomeZone * output)
{
  if (!input || !output) {
    return false;
  }
  // visible
  output->visible = input->visible;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // size
  output->size = input->size;
  return true;
}

assessment_interfaces__msg__HomeZone *
assessment_interfaces__msg__HomeZone__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  assessment_interfaces__msg__HomeZone * msg = (assessment_interfaces__msg__HomeZone *)allocator.allocate(sizeof(assessment_interfaces__msg__HomeZone), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(assessment_interfaces__msg__HomeZone));
  bool success = assessment_interfaces__msg__HomeZone__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
assessment_interfaces__msg__HomeZone__destroy(assessment_interfaces__msg__HomeZone * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    assessment_interfaces__msg__HomeZone__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
assessment_interfaces__msg__HomeZone__Sequence__init(assessment_interfaces__msg__HomeZone__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  assessment_interfaces__msg__HomeZone * data = NULL;

  if (size) {
    data = (assessment_interfaces__msg__HomeZone *)allocator.zero_allocate(size, sizeof(assessment_interfaces__msg__HomeZone), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = assessment_interfaces__msg__HomeZone__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        assessment_interfaces__msg__HomeZone__fini(&data[i - 1]);
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
assessment_interfaces__msg__HomeZone__Sequence__fini(assessment_interfaces__msg__HomeZone__Sequence * array)
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
      assessment_interfaces__msg__HomeZone__fini(&array->data[i]);
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

assessment_interfaces__msg__HomeZone__Sequence *
assessment_interfaces__msg__HomeZone__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  assessment_interfaces__msg__HomeZone__Sequence * array = (assessment_interfaces__msg__HomeZone__Sequence *)allocator.allocate(sizeof(assessment_interfaces__msg__HomeZone__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = assessment_interfaces__msg__HomeZone__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
assessment_interfaces__msg__HomeZone__Sequence__destroy(assessment_interfaces__msg__HomeZone__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    assessment_interfaces__msg__HomeZone__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
assessment_interfaces__msg__HomeZone__Sequence__are_equal(const assessment_interfaces__msg__HomeZone__Sequence * lhs, const assessment_interfaces__msg__HomeZone__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!assessment_interfaces__msg__HomeZone__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
assessment_interfaces__msg__HomeZone__Sequence__copy(
  const assessment_interfaces__msg__HomeZone__Sequence * input,
  assessment_interfaces__msg__HomeZone__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(assessment_interfaces__msg__HomeZone);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    assessment_interfaces__msg__HomeZone * data =
      (assessment_interfaces__msg__HomeZone *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!assessment_interfaces__msg__HomeZone__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          assessment_interfaces__msg__HomeZone__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!assessment_interfaces__msg__HomeZone__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
