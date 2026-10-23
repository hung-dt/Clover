#include "Clover.hpp"

/*--------------------------------------------------------------------------*/

class SandboxApp : public clover::Application
{};

/*--------------------------------------------------------------------------*/

clover::Application* clover::createApplication()
{
  return new SandboxApp();
}
