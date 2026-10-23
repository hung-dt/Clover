#include "Application.hpp"
#include "Log.hpp"
#include "Events/ApplicationEvent.hpp"

namespace clover {

/*--------------------------------------------------------------------------*/

Application::Application()
  : window_(Window::create())
{
}

/*--------------------------------------------------------------------------*/

void Application::run()
{
  isRunning_ = true;
  while ( isRunning_ ) {
    window_->onUpdate();
  }
}

}  // namespace clover
