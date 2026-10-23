#include "Application.hpp"
#include "Log.hpp"
#include "Events/ApplicationEvent.hpp"

namespace clover {

/*--------------------------------------------------------------------------*/

void Application::run()
{
  WindowResizeEvent e{ 1280, 720 };

  CLV_CORE_LOG_TRACE(e);

  while ( true )
    ;
}

}  // namespace clover
