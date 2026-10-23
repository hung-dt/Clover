#pragma once

#include "Core.hpp"
#include "LayerStack.hpp"
#include "Window.hpp"

namespace clover {

class Event;

class WindowCloseEvent;

/*--------------------------------------------------------------------------*/

class CLV_API Application
{
public:
  Application();

  virtual ~Application() = default;

  inline static Application& get() { return *instance_; }

  void run();

  void onEvent(Event& event);

  void pushLayer(Layer*);

  void pushOverlay(Layer*);

  Window& window() { return *window_; }

private:
  inline static Application* instance_{ nullptr };

  WindowPtr window_;

  bool isRunning_{ false };

  LayerStack layerStack_;

  bool onWindowClosed(WindowCloseEvent& e);
};

/*--------------------------------------------------------------------------*/

// To be defined in client
Application* createApplication();

}  // namespace clover
