#pragma once
//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class definition for Window on Windows platform
//===========================================================================

#include "Window.hpp"

#include <GLFW/glfw3.h>

/*--------------------------------------------------------------------------*/

namespace clover {

/*--------------------------------------------------------------------------*/

class WindowWin : public Window
{
public:
  WindowWin(const WindowProps& props);

  ~WindowWin();

  void onUpdate() override;

  unsigned width() const override { return data_.props.width; }

  unsigned height() const override { return data_.props.height; }

  // Window attributes
  void setEventCallback(const EventCallbackFn& callback) override
  {
    data_.eventCallback = callback;
  }

  void setVSync(bool enable) override;

  bool isVSync() const override { return data_.isVSync; }

private:
  GLFWwindow* window_;

  struct WindowData
  {
    WindowProps props;
    bool isVSync;
    EventCallbackFn eventCallback;
  } data_;

  virtual void init(const WindowProps& props);
  virtual void shutdown();
};

}  // namespace clover
