// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from solution_interfaces:srv/RandomGoal.idl
// generated code does not contain a copyright notice

#ifndef SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__BUILDER_HPP_
#define SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "solution_interfaces/srv/detail/random_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace solution_interfaces
{

namespace srv
{

namespace builder
{

class Init_RandomGoal_Request_y
{
public:
  explicit Init_RandomGoal_Request_y(::solution_interfaces::srv::RandomGoal_Request & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::srv::RandomGoal_Request y(::solution_interfaces::srv::RandomGoal_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::srv::RandomGoal_Request msg_;
};

class Init_RandomGoal_Request_x
{
public:
  Init_RandomGoal_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RandomGoal_Request_y x(::solution_interfaces::srv::RandomGoal_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RandomGoal_Request_y(msg_);
  }

private:
  ::solution_interfaces::srv::RandomGoal_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::srv::RandomGoal_Request>()
{
  return solution_interfaces::srv::builder::Init_RandomGoal_Request_x();
}

}  // namespace solution_interfaces


namespace solution_interfaces
{

namespace srv
{

namespace builder
{

class Init_RandomGoal_Response_angle
{
public:
  explicit Init_RandomGoal_Response_angle(::solution_interfaces::srv::RandomGoal_Response & msg)
  : msg_(msg)
  {}
  ::solution_interfaces::srv::RandomGoal_Response angle(::solution_interfaces::srv::RandomGoal_Response::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::solution_interfaces::srv::RandomGoal_Response msg_;
};

class Init_RandomGoal_Response_new_y
{
public:
  explicit Init_RandomGoal_Response_new_y(::solution_interfaces::srv::RandomGoal_Response & msg)
  : msg_(msg)
  {}
  Init_RandomGoal_Response_angle new_y(::solution_interfaces::srv::RandomGoal_Response::_new_y_type arg)
  {
    msg_.new_y = std::move(arg);
    return Init_RandomGoal_Response_angle(msg_);
  }

private:
  ::solution_interfaces::srv::RandomGoal_Response msg_;
};

class Init_RandomGoal_Response_new_x
{
public:
  Init_RandomGoal_Response_new_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RandomGoal_Response_new_y new_x(::solution_interfaces::srv::RandomGoal_Response::_new_x_type arg)
  {
    msg_.new_x = std::move(arg);
    return Init_RandomGoal_Response_new_y(msg_);
  }

private:
  ::solution_interfaces::srv::RandomGoal_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::solution_interfaces::srv::RandomGoal_Response>()
{
  return solution_interfaces::srv::builder::Init_RandomGoal_Response_new_x();
}

}  // namespace solution_interfaces

#endif  // SOLUTION_INTERFACES__SRV__DETAIL__RANDOM_GOAL__BUILDER_HPP_
