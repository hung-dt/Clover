//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class implementation for Window on Windows platform
//===========================================================================

#include "WindowWin.hpp"
#include "Log.hpp"

namespace clover {

inline static bool isGLFWInitialized = false;

/*--------------------------------------------------------------------------*/

Window* Window::create(const WindowProps& props)
{
  return new WindowWin(props);
}

/*--------------------------------------------------------------------------*/

WindowWin::WindowWin(const WindowProps& props)
{
  init(props);
}

/*--------------------------------------------------------------------------*/

WindowWin::~WindowWin()
{
  // TODO: to be implemented
  shutdown();
}

/*--------------------------------------------------------------------------*/

void WindowWin::init(const WindowProps& props)
{
  data_.props = props;

  CLV_CORE_LOG_INFO(
    "Creating window titled '{}' ({}, {})",
    props.title,
    props.width,
    props.height);

  if ( !isGLFWInitialized ) {
    // TODO: glfwTerminate on system shutdown
    int success = glfwInit();
    CLV_CORE_ASSERT(success, "Could not initialize GLFW");

    isGLFWInitialized = true;
  }

  window_ = glfwCreateWindow(
    (int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);

  glfwMakeContextCurrent(window_);
  glfwSetWindowUserPointer(window_, &data_);
  setVSync(true);
}

/*--------------------------------------------------------------------------*/

void WindowWin::shutdown()
{
  glfwDestroyWindow(window_);
}

/*--------------------------------------------------------------------------*/

void WindowWin::onUpdate()
{
  glfwPollEvents();
  glfwSwapBuffers(window_);
}

/*--------------------------------------------------------------------------*/

void WindowWin::setVSync(bool enabled)
{
  glfwSwapInterval(enabled ? 1 : 0);
  data_.isVSync = enabled;
}

}  // namespace clover
