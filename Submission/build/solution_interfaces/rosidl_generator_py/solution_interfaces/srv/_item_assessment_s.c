// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from solution_interfaces:srv/ItemAssessment.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "solution_interfaces/srv/detail/item_assessment__struct.h"
#include "solution_interfaces/srv/detail/item_assessment__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool assessment_interfaces__msg__item_list__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * assessment_interfaces__msg__item_list__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool solution_interfaces__srv__item_assessment__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("solution_interfaces.srv._item_assessment.ItemAssessment_Request", full_classname_dest, 63) == 0);
  }
  solution_interfaces__srv__ItemAssessment_Request * ros_message = _ros_message;
  {  // value
    PyObject * field = PyObject_GetAttrString(_pymsg, "value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->value = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // items
    PyObject * field = PyObject_GetAttrString(_pymsg, "items");
    if (!field) {
      return false;
    }
    if (!assessment_interfaces__msg__item_list__convert_from_py(field, &ros_message->items)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * solution_interfaces__srv__item_assessment__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ItemAssessment_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("solution_interfaces.srv._item_assessment");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ItemAssessment_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  solution_interfaces__srv__ItemAssessment_Request * ros_message = (solution_interfaces__srv__ItemAssessment_Request *)raw_ros_message;
  {  // value
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // items
    PyObject * field = NULL;
    field = assessment_interfaces__msg__item_list__convert_to_py(&ros_message->items);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "items", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "solution_interfaces/srv/detail/item_assessment__struct.h"
// already included above
// #include "solution_interfaces/srv/detail/item_assessment__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool assessment_interfaces__msg__item__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * assessment_interfaces__msg__item__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool solution_interfaces__srv__item_assessment__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("solution_interfaces.srv._item_assessment.ItemAssessment_Response", full_classname_dest, 64) == 0);
  }
  solution_interfaces__srv__ItemAssessment_Response * ros_message = _ros_message;
  {  // item
    PyObject * field = PyObject_GetAttrString(_pymsg, "item");
    if (!field) {
      return false;
    }
    if (!assessment_interfaces__msg__item__convert_from_py(field, &ros_message->item)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * solution_interfaces__srv__item_assessment__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ItemAssessment_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("solution_interfaces.srv._item_assessment");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ItemAssessment_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  solution_interfaces__srv__ItemAssessment_Response * ros_message = (solution_interfaces__srv__ItemAssessment_Response *)raw_ros_message;
  {  // item
    PyObject * field = NULL;
    field = assessment_interfaces__msg__item__convert_to_py(&ros_message->item);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "item", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
