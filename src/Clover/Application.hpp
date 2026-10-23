#pragma once

#include "Core.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Events/Event.hpp"
#include "Window.hpp"

namespace clover {

/*--------------------------------------------------------------------------*/

class CLV_API Application
{
public:
  Application();

  virtual ~Application() = default;

  void run();

  void onEvent(Event& event);

private:
  WindowPtr window_;

  bool isRunning_{ false };

  bool onWindowClosed(WindowCloseEvent& e);
};

/*--------------------------------------------------------------------------*/

// To be defined in client
Application* createApplication();

}  // namespace clover
