// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from solution_interfaces:msg/HomePubPosition.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__MSG__DETAIL__HOME_PUB_POSITION__FUNCTIONS_H_
#define SOLUTION_INTERFACES__MSG__DETAIL__HOME_PUB_POSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "solution_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "solution_interfaces/msg/detail/home_pub_position__struct.h"

/// Initialize msg/HomePubPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * solution_interfaces__msg__HomePubPosition
 * )) before or use
 * solution_interfaces__msg__HomePubPosition__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__HomePubPosition__init(solution_interfaces__msg__HomePubPosition * msg);

/// Finalize msg/HomePubPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
void
solution_interfaces__msg__HomePubPosition__fini(solution_interfaces__msg__HomePubPosition * msg);

/// Create msg/HomePubPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * solution_interfaces__msg__HomePubPosition__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
solution_interfaces__msg__HomePubPosition *
solution_interfaces__msg__HomePubPosition__create();

/// Destroy msg/HomePubPosition message.
/**
 * It calls
 * solution_interfaces__msg__HomePubPosition__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
void
solution_interfaces__msg__HomePubPosition__destroy(solution_interfaces__msg__HomePubPosition * msg);

/// Check for msg/HomePubPosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__HomePubPosition__are_equal(const solution_interfaces__msg__HomePubPosition * lhs, const solution_interfaces__msg__HomePubPosition * rhs);

/// Copy a msg/HomePubPosition message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__HomePubPosition__copy(
  const solution_interfaces__msg__HomePubPosition * input,
  solution_interfaces__msg__HomePubPosition * output);

/// Initialize array of msg/HomePubPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * solution_interfaces__msg__HomePubPosition__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__HomePubPosition__Sequence__init(solution_interfaces__msg__HomePubPosition__Sequence * array, size_t size);

/// Finalize array of msg/HomePubPosition messages.
/**
 * It calls
 * solution_interfaces__msg__HomePubPosition__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
void
solution_interfaces__msg__HomePubPosition__Sequence__fini(solution_interfaces__msg__HomePubPosition__Sequence * array);

/// Create array of msg/HomePubPosition messages.
/**
 * It allocates the memory for the array and calls
 * solution_interfaces__msg__HomePubPosition__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
solution_interfaces__msg__HomePubPosition__Sequence *
solution_interfaces__msg__HomePubPosition__Sequence__create(size_t size);

/// Destroy array of msg/HomePubPosition messages.
/**
 * It calls
 * solution_interfaces__msg__HomePubPosition__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
void
solution_interfaces__msg__HomePubPosition__Sequence__destroy(solution_interfaces__msg__HomePubPosition__Sequence * array);

/// Check for msg/HomePubPosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__HomePubPosition__Sequence__are_equal(const solution_interfaces__msg__HomePubPosition__Sequence * lhs, const solution_interfaces__msg__HomePubPosition__Sequence * rhs);

/// Copy an array of msg/HomePubPosition messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_solution_interfaces
bool
solution_interfaces__msg__HomePubPosition__Sequence__copy(
  const solution_interfaces__msg__HomePubPosition__Sequence * input,
  solution_interfaces__msg__HomePubPosition__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SOLUTION_INTERFACES__MSG__DETAIL__HOME_PUB_POSITION__FUNCTIONS_H_
