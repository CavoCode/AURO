// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from solution_interfaces:srv/ItemAssessment.idl
// generated code does not contain a copyright notice
#include "solution_interfaces/srv/detail/item_assessment__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `items`
#include "assessment_interfaces/msg/detail/item_list__functions.h"

bool
solution_interfaces__srv__ItemAssessment_Request__init(solution_interfaces__srv__ItemAssessment_Request * msg)
{
  if (!msg) {
    return false;
  }
  // value
  // items
  if (!assessment_interfaces__msg__ItemList__init(&msg->items)) {
    solution_interfaces__srv__ItemAssessment_Request__fini(msg);
    return false;
  }
  return true;
}

void
solution_interfaces__srv__ItemAssessment_Request__fini(solution_interfaces__srv__ItemAssessment_Request * msg)
{
  if (!msg) {
    return;
  }
  // value
  // items
  assessment_interfaces__msg__ItemList__fini(&msg->items);
}

bool
solution_interfaces__srv__ItemAssessment_Request__are_equal(const solution_interfaces__srv__ItemAssessment_Request * lhs, const solution_interfaces__srv__ItemAssessment_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  // items
  if (!assessment_interfaces__msg__ItemList__are_equal(
      &(lhs->items), &(rhs->items)))
  {
    return false;
  }
  return true;
}

bool
solution_interfaces__srv__ItemAssessment_Request__copy(
  const solution_interfaces__srv__ItemAssessment_Request * input,
  solution_interfaces__srv__ItemAssessment_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // value
  output->value = input->value;
  // items
  if (!assessment_interfaces__msg__ItemList__copy(
      &(input->items), &(output->items)))
  {
    return false;
  }
  return true;
}

solution_interfaces__srv__ItemAssessment_Request *
solution_interfaces__srv__ItemAssessment_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__ItemAssessment_Request * msg = (solution_interfaces__srv__ItemAssessment_Request *)allocator.allocate(sizeof(solution_interfaces__srv__ItemAssessment_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(solution_interfaces__srv__ItemAssessment_Request));
  bool success = solution_interfaces__srv__ItemAssessment_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
solution_interfaces__srv__ItemAssessment_Request__destroy(solution_interfaces__srv__ItemAssessment_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    solution_interfaces__srv__ItemAssessment_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
solution_interfaces__srv__ItemAssessment_Request__Sequence__init(solution_interfaces__srv__ItemAssessment_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__ItemAssessment_Request * data = NULL;

  if (size) {
    data = (solution_interfaces__srv__ItemAssessment_Request *)allocator.zero_allocate(size, sizeof(solution_interfaces__srv__ItemAssessment_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = solution_interfaces__srv__ItemAssessment_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        solution_interfaces__srv__ItemAssessment_Request__fini(&data[i - 1]);
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
solution_interfaces__srv__ItemAssessment_Request__Sequence__fini(solution_interfaces__srv__ItemAssessment_Request__Sequence * array)
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
      solution_interfaces__srv__ItemAssessment_Request__fini(&array->data[i]);
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

solution_interfaces__srv__ItemAssessment_Request__Sequence *
solution_interfaces__srv__ItemAssessment_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__ItemAssessment_Request__Sequence * array = (solution_interfaces__srv__ItemAssessment_Request__Sequence *)allocator.allocate(sizeof(solution_interfaces__srv__ItemAssessment_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = solution_interfaces__srv__ItemAssessment_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
solution_interfaces__srv__ItemAssessment_Request__Sequence__destroy(solution_interfaces__srv__ItemAssessment_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    solution_interfaces__srv__ItemAssessment_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
solution_interfaces__srv__ItemAssessment_Request__Sequence__are_equal(const solution_interfaces__srv__ItemAssessment_Request__Sequence * lhs, const solution_interfaces__srv__ItemAssessment_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!solution_interfaces__srv__ItemAssessment_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
solution_interfaces__srv__ItemAssessment_Request__Sequence__copy(
  const solution_interfaces__srv__ItemAssessment_Request__Sequence * input,
  solution_interfaces__srv__ItemAssessment_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(solution_interfaces__srv__ItemAssessment_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    solution_interfaces__srv__ItemAssessment_Request * data =
      (solution_interfaces__srv__ItemAssessment_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!solution_interfaces__srv__ItemAssessment_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          solution_interfaces__srv__ItemAssessment_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!solution_interfaces__srv__ItemAssessment_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `item`
#include "assessment_interfaces/msg/detail/item__functions.h"

bool
solution_interfaces__srv__ItemAssessment_Response__init(solution_interfaces__srv__ItemAssessment_Response * msg)
{
  if (!msg) {
    return false;
  }
  // item
  if (!assessment_interfaces__msg__Item__init(&msg->item)) {
    solution_interfaces__srv__ItemAssessment_Response__fini(msg);
    return false;
  }
  // distance
  return true;
}

void
solution_interfaces__srv__ItemAssessment_Response__fini(solution_interfaces__srv__ItemAssessment_Response * msg)
{
  if (!msg) {
    return;
  }
  // item
  assessment_interfaces__msg__Item__fini(&msg->item);
  // distance
}

bool
solution_interfaces__srv__ItemAssessment_Response__are_equal(const solution_interfaces__srv__ItemAssessment_Response * lhs, const solution_interfaces__srv__ItemAssessment_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // item
  if (!assessment_interfaces__msg__Item__are_equal(
      &(lhs->item), &(rhs->item)))
  {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  return true;
}

bool
solution_interfaces__srv__ItemAssessment_Response__copy(
  const solution_interfaces__srv__ItemAssessment_Response * input,
  solution_interfaces__srv__ItemAssessment_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // item
  if (!assessment_interfaces__msg__Item__copy(
      &(input->item), &(output->item)))
  {
    return false;
  }
  // distance
  output->distance = input->distance;
  return true;
}

solution_interfaces__srv__ItemAssessment_Response *
solution_interfaces__srv__ItemAssessment_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__ItemAssessment_Response * msg = (solution_interfaces__srv__ItemAssessment_Response *)allocator.allocate(sizeof(solution_interfaces__srv__ItemAssessment_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(solution_interfaces__srv__ItemAssessment_Response));
  bool success = solution_interfaces__srv__ItemAssessment_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
solution_interfaces__srv__ItemAssessment_Response__destroy(solution_interfaces__srv__ItemAssessment_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    solution_interfaces__srv__ItemAssessment_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
solution_interfaces__srv__ItemAssessment_Response__Sequence__init(solution_interfaces__srv__ItemAssessment_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__ItemAssessment_Response * data = NULL;

  if (size) {
    data = (solution_interfaces__srv__ItemAssessment_Response *)allocator.zero_allocate(size, sizeof(solution_interfaces__srv__ItemAssessment_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = solution_interfaces__srv__ItemAssessment_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        solution_interfaces__srv__ItemAssessment_Response__fini(&data[i - 1]);
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
solution_interfaces__srv__ItemAssessment_Response__Sequence__fini(solution_interfaces__srv__ItemAssessment_Response__Sequence * array)
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
      solution_interfaces__srv__ItemAssessment_Response__fini(&array->data[i]);
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

solution_interfaces__srv__ItemAssessment_Response__Sequence *
solution_interfaces__srv__ItemAssessment_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  solution_interfaces__srv__ItemAssessment_Response__Sequence * array = (solution_interfaces__srv__ItemAssessment_Response__Sequence *)allocator.allocate(sizeof(solution_interfaces__srv__ItemAssessment_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = solution_interfaces__srv__ItemAssessment_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
solution_interfaces__srv__ItemAssessment_Response__Sequence__destroy(solution_interfaces__srv__ItemAssessment_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    solution_interfaces__srv__ItemAssessment_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
solution_interfaces__srv__ItemAssessment_Response__Sequence__are_equal(const solution_interfaces__srv__ItemAssessment_Response__Sequence * lhs, const solution_interfaces__srv__ItemAssessment_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!solution_interfaces__srv__ItemAssessment_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
solution_interfaces__srv__ItemAssessment_Response__Sequence__copy(
  const solution_interfaces__srv__ItemAssessment_Response__Sequence * input,
  solution_interfaces__srv__ItemAssessment_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(solution_interfaces__srv__ItemAssessment_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    solution_interfaces__srv__ItemAssessment_Response * data =
      (solution_interfaces__srv__ItemAssessment_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!solution_interfaces__srv__ItemAssessment_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          solution_interfaces__srv__ItemAssessment_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!solution_interfaces__srv__ItemAssessment_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
