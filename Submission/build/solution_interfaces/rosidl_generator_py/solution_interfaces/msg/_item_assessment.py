# generated from rosidl_generator_py/resource/_idl.py.em
# with input from solution_interfaces:msg/ItemAssessment.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ItemAssessment(type):
    """Metaclass of message 'ItemAssessment'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('solution_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'solution_interfaces.msg.ItemAssessment')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__item_assessment
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__item_assessment
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__item_assessment
            cls._TYPE_SUPPORT = module.type_support_msg__msg__item_assessment
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__item_assessment

            from geometry_msgs.msg import PointStamped
            if PointStamped.__class__._TYPE_SUPPORT is None:
                PointStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ItemAssessment(metaclass=Metaclass_ItemAssessment):
    """Message class 'ItemAssessment'."""

    __slots__ = [
        '_goal_point_stamped',
        '_goal_type',
    ]

    _fields_and_field_types = {
        'goal_point_stamped': 'geometry_msgs/PointStamped',
        'goal_type': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PointStamped'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import PointStamped
        self.goal_point_stamped = kwargs.get('goal_point_stamped', PointStamped())
        self.goal_type = kwargs.get('goal_type', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_point_stamped != other.goal_point_stamped:
            return False
        if self.goal_type != other.goal_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_point_stamped(self):
        """Message field 'goal_point_stamped'."""
        return self._goal_point_stamped

    @goal_point_stamped.setter
    def goal_point_stamped(self, value):
        if __debug__:
            from geometry_msgs.msg import PointStamped
            assert \
                isinstance(value, PointStamped), \
                "The 'goal_point_stamped' field must be a sub message of type 'PointStamped'"
        self._goal_point_stamped = value

    @builtins.property
    def goal_type(self):
        """Message field 'goal_type'."""
        return self._goal_type

    @goal_type.setter
    def goal_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'goal_type' field must be of type 'str'"
        self._goal_type = value
