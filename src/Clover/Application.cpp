#include "Application.hpp"
#include "Log.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Events/Event.hpp"

#include <ranges>

namespace clover {

// #define BIND_EVENT_FN(e) std::bind(&Application::e, this,
// std::placeholders::_1)
#define BIND_EVENT_FN(evFn) [this](Event& ev) { this->evFn(ev); }
#define BIND_EVENT_BOOL_FN(evFn, evType)        \
  [this](evType& ev) { return this->evFn(ev); }

/*--------------------------------------------------------------------------*/

Application::Application()
  : window_(Window::create())
{
  window_->setEventCallback(BIND_EVENT_FN(onEvent));
}

/*--------------------------------------------------------------------------*/

void Application::run()
{
  isRunning_ = true;
  while ( isRunning_ ) {
    for ( auto layer : layerStack_ ) {
      layer->onUpdate();
    }

    window_->onUpdate();
  }
}

/*--------------------------------------------------------------------------*/

void Application::onEvent(Event& event)
{
  EventDispatcher dispatcher(event);
  dispatcher.dispatch<WindowCloseEvent>(
    BIND_EVENT_BOOL_FN(onWindowClosed, WindowCloseEvent));

  CLV_CORE_LOG_INFO("Handle {}", event);

  // handle events for layers
  for ( auto layer : std::views::reverse(layerStack_) ) {
    layer->onEvent(event);
    // once the event is handled it will not be propagated down
    if ( event.isHandled() ) {
      break;
    }
  }
}

/*--------------------------------------------------------------------------*/

void Application::pushLayer(Layer* layer)
{
  layerStack_.push(layer);
}

/*--------------------------------------------------------------------------*/

void Application::pushOverlay(Layer* overlay)
{
  layerStack_.pushOverlay(overlay);
}

/*--------------------------------------------------------------------------*/

/** Handle window closed event
 */
bool Application::onWindowClosed(WindowCloseEvent& event)
{
  isRunning_ = false;
  return true;
}

}  // namespace clover
