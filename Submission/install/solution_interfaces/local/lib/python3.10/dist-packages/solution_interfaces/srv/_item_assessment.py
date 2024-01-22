# generated from rosidl_generator_py/resource/_idl.py.em
# with input from solution_interfaces:srv/ItemAssessment.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ItemAssessment_Request(type):
    """Metaclass of message 'ItemAssessment_Request'."""

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
                'solution_interfaces.srv.ItemAssessment_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__item_assessment__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__item_assessment__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__item_assessment__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__item_assessment__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__item_assessment__request

            from assessment_interfaces.msg import ItemList
            if ItemList.__class__._TYPE_SUPPORT is None:
                ItemList.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ItemAssessment_Request(metaclass=Metaclass_ItemAssessment_Request):
    """Message class 'ItemAssessment_Request'."""

    __slots__ = [
        '_value',
        '_items',
    ]

    _fields_and_field_types = {
        'value': 'uint8',
        'items': 'assessment_interfaces/ItemList',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['assessment_interfaces', 'msg'], 'ItemList'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.value = kwargs.get('value', int())
        from assessment_interfaces.msg import ItemList
        self.items = kwargs.get('items', ItemList())

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
        if self.value != other.value:
            return False
        if self.items != other.items:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def value(self):
        """Message field 'value'."""
        return self._value

    @value.setter
    def value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'value' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'value' field must be an unsigned integer in [0, 255]"
        self._value = value

    @builtins.property
    def items(self):
        """Message field 'items'."""
        return self._items

    @items.setter
    def items(self, value):
        if __debug__:
            from assessment_interfaces.msg import ItemList
            assert \
                isinstance(value, ItemList), \
                "The 'items' field must be a sub message of type 'ItemList'"
        self._items = value


# Import statements for member types

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_ItemAssessment_Response(type):
    """Metaclass of message 'ItemAssessment_Response'."""

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
                'solution_interfaces.srv.ItemAssessment_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__item_assessment__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__item_assessment__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__item_assessment__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__item_assessment__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__item_assessment__response

            from assessment_interfaces.msg import Item
            if Item.__class__._TYPE_SUPPORT is None:
                Item.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ItemAssessment_Response(metaclass=Metaclass_ItemAssessment_Response):
    """Message class 'ItemAssessment_Response'."""

    __slots__ = [
        '_item',
        '_distance',
    ]

    _fields_and_field_types = {
        'item': 'assessment_interfaces/Item',
        'distance': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['assessment_interfaces', 'msg'], 'Item'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from assessment_interfaces.msg import Item
        self.item = kwargs.get('item', Item())
        self.distance = kwargs.get('distance', float())

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
        if self.item != other.item:
            return False
        if self.distance != other.distance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def item(self):
        """Message field 'item'."""
        return self._item

    @item.setter
    def item(self, value):
        if __debug__:
            from assessment_interfaces.msg import Item
            assert \
                isinstance(value, Item), \
                "The 'item' field must be a sub message of type 'Item'"
        self._item = value

    @builtins.property
    def distance(self):
        """Message field 'distance'."""
        return self._distance

    @distance.setter
    def distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._distance = value


class Metaclass_ItemAssessment(type):
    """Metaclass of service 'ItemAssessment'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('solution_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'solution_interfaces.srv.ItemAssessment')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__item_assessment

            from solution_interfaces.srv import _item_assessment
            if _item_assessment.Metaclass_ItemAssessment_Request._TYPE_SUPPORT is None:
                _item_assessment.Metaclass_ItemAssessment_Request.__import_type_support__()
            if _item_assessment.Metaclass_ItemAssessment_Response._TYPE_SUPPORT is None:
                _item_assessment.Metaclass_ItemAssessment_Response.__import_type_support__()


class ItemAssessment(metaclass=Metaclass_ItemAssessment):
    from solution_interfaces.srv._item_assessment import ItemAssessment_Request as Request
    from solution_interfaces.srv._item_assessment import ItemAssessment_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
