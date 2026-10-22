#include "Clover.hpp"

/*--------------------------------------------------------------------------*/

class Sandbox : public clover::Application
{};

/*--------------------------------------------------------------------------*/

clover::Application* clover::createApplication()
{
  return new Sandbox();
}
