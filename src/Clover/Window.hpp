#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for abstract Window
//===========================================================================

#include "Core.hpp"
#include "Events/Event.hpp"

/*--------------------------------------------------------------------------*/

namespace clover {

/*--------------------------------------------------------------------------*/

struct WindowProps
{
  std::string title{};
  unsigned width{};
  unsigned height{};

  WindowProps(
    const std::string& t = "Clover Engine",
    const unsigned w = 1280,
    const unsigned h = 720)
    : title(t)
    , width(w)
    , height(h)
  {
  }
};

/*--------------------------------------------------------------------------*/

/** Interface representing a desktop system based window
 */
class CLV_API Window
{
public:
  using EventCallbackFn = std::function<void(Event&)>;

  virtual ~Window() = default;

  virtual void onUpdate() = 0;

  virtual unsigned width() const = 0;

  virtual unsigned height() const = 0;

  // Window attributes
  virtual void setEventCallback(const EventCallbackFn& callback) = 0;
  virtual void setVSync(bool enable) = 0;
  virtual bool isVSync() const = 0;

  static Window* create(const WindowProps& props = WindowProps());
};

using WindowPtr = std::unique_ptr<Window>;

}  // namespace clover
