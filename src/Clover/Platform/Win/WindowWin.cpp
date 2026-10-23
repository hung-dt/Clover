//===========================================================================
//  Author     : hung-dt (dth.online@gmail.com)
//  Created    : 2026-10-23
//  Description: Class implementation for Window on Windows platform
//===========================================================================

#include "WindowWin.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"
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

    glfwSetErrorCallback([](int error_code, const char* description) {
      CLV_CORE_LOG_ERROR("GLFW error ({}): {}", error_code, description);
    });

    isGLFWInitialized = true;
  }

  window_ = glfwCreateWindow(
    (int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);

  glfwMakeContextCurrent(window_);
  glfwSetWindowUserPointer(window_, &data_);
  setVSync(true);

  // set GLFW callbacks
  glfwSetWindowSizeCallback(
    window_, [](GLFWwindow* window, int width, int height) {
      auto winData =
        reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

      winData->props.width = width;
      winData->props.height = height;

      WindowResizeEvent event(width, height);
      winData->eventCallback(event);
    });

  glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
    auto winData =
      reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

    WindowCloseEvent event{};
    winData->eventCallback(event);
  });

  glfwSetKeyCallback(
    window_,
    [](GLFWwindow* window, int key, int scancode, int action, int mods) {
      auto winData =
        reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

      switch ( action ) {
        case GLFW_PRESS: {
          KeyPressedEvent event{ key, 0 };
          winData->eventCallback(event);
          break;
        }
        case GLFW_RELEASE: {
          KeyReleasedEvent event{ key };
          winData->eventCallback(event);
          break;
        }
        case GLFW_REPEAT: {
          KeyPressedEvent event{ key, 1 };
          winData->eventCallback(event);
          break;
        }
      }
    });

  glfwSetMouseButtonCallback(
    window_, [](GLFWwindow* window, int button, int action, int mods) {
      auto winData =
        reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

      switch ( action ) {
        case GLFW_PRESS: {
          MouseButtonPressedEvent event{ button };
          winData->eventCallback(event);
          break;
        }
        case GLFW_RELEASE: {
          MouseButtonReleasedEvent event{ button };
          winData->eventCallback(event);
          break;
        }
      }
    });

  glfwSetScrollCallback(
    window_, [](GLFWwindow* window, double xoffset, double yoffset) {
      auto winData =
        reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

      MouseScrolledEvent event{ static_cast<float>(xoffset),
                                static_cast<float>(yoffset) };
      winData->eventCallback(event);
    });

  glfwSetCursorPosCallback(
    window_, [](GLFWwindow* window, double xPos, double yPos) {
      auto winData =
        reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

      MouseMovedEvent event{ static_cast<float>(xPos),
                             static_cast<float>(yPos) };
      winData->eventCallback(event);
    });
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
