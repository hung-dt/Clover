#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for Events
//===========================================================================
#include "clvpch.hpp"

#include "Core.hpp"

/*--------------------------------------------------------------------------*/

namespace clover {

/** Events in Clover are currently blocking, meaning when an event occurs
 * it immediately gets dispatched and must be dealt with.
 * For the future, a better strategy might be to buffer events in an event
 * queue and process them during the "event" part of the update state.
 */

enum class EventType
{
  None = 0,
  WindowClose,
  WindowResize,
  WindowFocus,
  WindowLostFocus,
  WindowMoved,
  AppTick,
  AppUpdate,
  AppRender,
  KeyPressed,
  KeyReleased,
  MouseButtonPressed,
  MouseButtonReleased,
  MouseMoved,
  MouseScrolled
};

/** Used to filter certain events */
enum EventCategory
{
  None = 0,
  EventCategoryApplication = BIT(0),
  EventCategoryInput = BIT(1),
  EventCategoryKeyboard = BIT(2),
  EventCategoryMouse = BIT(3),
  EventCategoryMouseButton = BIT(4)
};

#define EVENT_CLASS_TYPE(etype)     \
  static EventType staticType()     \
  {                                 \
    return EventType::etype;        \
  }                                 \
  EventType type() const override   \
  {                                 \
    return staticType();            \
  }                                 \
  const char* name() const override \
  {                                 \
    return #etype "Event";          \
  }

#define EVENT_CLASS_CATEGORY(cat)    \
  int categoryFlags() const override \
  {                                  \
    return cat;                      \
  }

/*--------------------------------------------------------------------------*/

class CLV_API Event
{
  friend class EventDispatcher;

public:
  virtual ~Event() = default;

  virtual EventType type() const = 0;

  virtual const char* name() const = 0;

  virtual int categoryFlags() const = 0;

  virtual std::string str() const { return name(); }

  inline bool isInCategory(EventCategory cat) { return categoryFlags() & cat; }

protected:
  bool isHandled_{ false };
};

/*--------------------------------------------------------------------------*/

class EventDispatcher
{
  template <typename T>
  using EventFn = std::function<bool(T&)>;

public:
  EventDispatcher(Event& event)
    : event_(event)
  {
  }

  template <typename T>
  bool dispatch(EventFn<T> handler)
  {
    if ( event_.type() == T::staticType() ) {
      event_.isHandled_ = handler(*(T*)&event_);
      return true;
    }
    return false;
  }

private:
  Event& event_;
};

/*--------------------------------------------------------------------------*/

inline std::string format_as(const Event& e)
{
  return e.str();
}

}  // namespace clover
