#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"

namespace clover {

/*--------------------------------------------------------------------------*/

class CLV_API Application
{
public:
  virtual ~Application() = default;

  void run();
};

/*--------------------------------------------------------------------------*/

// To be defined in client
Application* createApplication();

}  // namespace clover
