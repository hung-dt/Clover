#pragma once

#include "Core.hpp"
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

private:
  WindowPtr window_;

  bool isRunning_{ false };
};

/*--------------------------------------------------------------------------*/

// To be defined in client
Application* createApplication();

}  // namespace clover
