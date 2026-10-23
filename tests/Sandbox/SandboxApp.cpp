#include "Clover.hpp"

/*--------------------------------------------------------------------------*/

class TestLayer : public clover::Layer
{
public:
  TestLayer()
    : clover::Layer("Test")
  {
  }

  void onUpdate() override { CLV_CLIENT_LOG_INFO("TestLayer::onUpdate"); }

  void onEvent(clover::Event& e) override { CLV_CLIENT_LOG_TRACE("{}", e); }
};

/*--------------------------------------------------------------------------*/

class SandboxApp : public clover::Application
{
public:
  SandboxApp() { pushLayer(new TestLayer); }
};

/*--------------------------------------------------------------------------*/

clover::Application* clover::createApplication()
{
  return new SandboxApp();
}
