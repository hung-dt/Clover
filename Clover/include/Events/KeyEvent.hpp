#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for keyboard events
//===========================================================================

#include "Event.hpp"

#include <format>

/*--------------------------------------------------------------------------*/

namespace clover {

/*--------------------------------------------------------------------------*/

class CLV_API MouseButtonEvent : public Event
{
public:
  inline int getMouseButton() const { return button_; }

  EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
  MouseButtonEvent(int keyCode)
    : button_(keyCode)
  {
  }

  int button_;
};

/*--------------------------------------------------------------------------*/

class CLV_API KeyPressedEvent : public MouseButtonEvent
{
public:
  KeyPressedEvent(int keyCode, int repeatCount)
    : MouseButtonEvent(keyCode)
    , repeatCount_(repeatCount)
  {
  }

  inline int getRepeatCount() const { return repeatCount_; }

  std::string str() const override
  {
    return std::format(
      "KeyPressedEvent: keycode={}, repeats={}", button_, repeatCount_);
  }

  EVENT_CLASS_TYPE(KeyPressed)

private:
  int repeatCount_;
};

/*--------------------------------------------------------------------------*/

class CLV_API KeyReleasedEvent : public MouseButtonEvent
{
public:
  KeyReleasedEvent(int keyCode)
    : MouseButtonEvent(keyCode)
  {
  }

  std::string str() const override
  {
    return std::format("KeyReleasedEvent: keycode={}", button_);
  }

  EVENT_CLASS_TYPE(KeyReleased)
};

}  // namespace clover
