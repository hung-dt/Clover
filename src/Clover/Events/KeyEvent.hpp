#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for keyboard events
//===========================================================================

#include "Event.hpp"

/*--------------------------------------------------------------------------*/

namespace clover {

/*--------------------------------------------------------------------------*/

class CLV_API KeyEvent : public Event
{
public:
  inline int getMouseButton() const { return button_; }

  EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
  KeyEvent(int keyCode)
    : button_(keyCode)
  {
  }

  int button_;
};

/*--------------------------------------------------------------------------*/

class CLV_API KeyPressedEvent : public KeyEvent
{
public:
  KeyPressedEvent(int keyCode, int repeatCount)
    : KeyEvent(keyCode)
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

class CLV_API KeyReleasedEvent : public KeyEvent
{
public:
  KeyReleasedEvent(int keyCode)
    : KeyEvent(keyCode)
  {
  }

  std::string str() const override
  {
    return std::format("KeyReleasedEvent: keycode={}", button_);
  }

  EVENT_CLASS_TYPE(KeyReleased)
};

}  // namespace clover
