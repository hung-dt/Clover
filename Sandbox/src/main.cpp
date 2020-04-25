#include "Clover.h"

class Sandbox : public clover::Application
{
public:
  Sandbox() = default;
  ~Sandbox() = default;
};

clover::Application* clover::createApplication()
{
  return new Sandbox();
}
