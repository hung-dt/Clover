#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for mouse events
//===========================================================================

#include "Event.hpp"

#include <format>

/*--------------------------------------------------------------------------*/

namespace clover {

/*--------------------------------------------------------------------------*/

class CLV_API MouseMovedEvent : public Event
{
public:
  MouseMovedEvent(float x, float y)
    : x_(x)
    , y_(y)
  {
  }

  inline float x() const { return x_; }

  inline float y() const { return y_; }

  std::string str() const override
  {
    return std::format("MouseMovedEvent: {}, {}", x_, y_);
  }

  EVENT_CLASS_TYPE(MouseMoved)

  EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

private:
  float x_{};
  float y_{};
};

/*--------------------------------------------------------------------------*/

class CLV_API MouseScrolledEvent : public Event
{
public:
  MouseScrolledEvent(float x, float y)
    : xOffset_(x)
    , yOffset_(y)
  {
  }

  inline float xOffset() const { return xOffset_; }

  inline float yOffset() const { return yOffset_; }

  std::string str() const override
  {
    return std::format("MouseScrolledEvent: {}, {}", xOffset_, yOffset_);
  }

  EVENT_CLASS_TYPE(MouseScrolled)

  EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

private:
  float xOffset_{};
  float yOffset_{};
};

/*--------------------------------------------------------------------------*/

class CLV_API MouseButtonEvent : public Event
{
public:
  inline int getMouseButton() const { return button_; }

  EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)

protected:
  MouseButtonEvent(int button)
    : button_(button)
  {
  }

  int button_;
};

/*--------------------------------------------------------------------------*/

class CLV_API MouseButtonPressedEvent : public MouseButtonEvent
{
public:
  MouseButtonPressedEvent(int button)
    : MouseButtonEvent(button)
  {
  }

  std::string str() const override
  {
    return std::format("MouseButtonPressedEvent: {}", button_);
  }

  EVENT_CLASS_TYPE(MouseButtonPressed)
};

/*--------------------------------------------------------------------------*/

class CLV_API MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
  MouseButtonReleasedEvent(int button)
    : MouseButtonEvent(button)
  {
  }

  std::string str() const override
  {
    return std::format("MouseButtonReleasedEvent: {}", button_);
  }

  EVENT_CLASS_TYPE(MouseButtonReleased)
};

}  // namespace clover
