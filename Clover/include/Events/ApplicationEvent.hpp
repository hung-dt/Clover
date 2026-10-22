#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for ApplicationEvent
//===========================================================================

#include "Event.hpp"

#include <format>

/*--------------------------------------------------------------------------*/

namespace clover {

/*--------------------------------------------------------------------------*/

class CLV_API WindowResizeEvent : public Event
{
public:
  WindowResizeEvent(unsigned width, unsigned height)
    : width_(width)
    , height_(height)
  {
  }

  inline unsigned width() const { return width_; }

  inline unsigned height() const { return height_; }

  std::string str() const override
  {
    return std::format("WindowResizeEvent: {}, {}", width_, height_);
  }

  EVENT_CLASS_TYPE(WindowResize)

  EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
  unsigned width_{};
  unsigned height_{};
};

/*--------------------------------------------------------------------------*/

class CLV_API WindowCloseEvent : public Event
{
public:
  EVENT_CLASS_TYPE(WindowClose)

  EVENT_CLASS_CATEGORY(EventCategoryApplication);
};

/*--------------------------------------------------------------------------*/

class AppTickEvent : public Event
{
public:
  EVENT_CLASS_TYPE(AppTick)

  EVENT_CLASS_CATEGORY(EventCategoryApplication);
};

/*--------------------------------------------------------------------------*/

class AppUpdateEvent : public Event
{
public:
  EVENT_CLASS_TYPE(AppUpdate)

  EVENT_CLASS_CATEGORY(EventCategoryApplication);
};

/*--------------------------------------------------------------------------*/

class AppRenderEvent : public Event
{
public:
  EVENT_CLASS_TYPE(AppRender)

  EVENT_CLASS_CATEGORY(EventCategoryApplication);
};

}  // namespace clover
