#pragma once

namespace clover {

class Application
{
public:
  Application();
  virtual ~Application();

  void run();

private:
};

Application* createApplication();

}  // namespace clover
