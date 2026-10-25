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
  inline int getKeyCode() const { return keyCode_; }

  EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
  KeyEvent(int keyCode)
    : keyCode_(keyCode)
  {
  }

  int keyCode_;
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
      "KeyPressedEvent: keycode={}, repeats={}", keyCode_, repeatCount_);
  }

  EVENT_CLASS_TYPE(KeyPressed)

private:
  int repeatCount_;
};

/*--------------------------------------------------------------------------*/

class CLV_API KeyTypedEvent : public KeyEvent
{
public:
  KeyTypedEvent(int keyCode)
    : KeyEvent(keyCode)
  {
  }

  std::string str() const override
  {
    return std::format("KeyTypedEvent: keycode={}", keyCode_);
  }

  EVENT_CLASS_TYPE(KeyTyped)
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
    return std::format("KeyReleasedEvent: keycode={}", keyCode_);
  }

  EVENT_CLASS_TYPE(KeyReleased)
};

}  // namespace clover
