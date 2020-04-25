#pragma once

#include "Clover.h"

#include <iostream>

int main( int argc, char const* argv[] )
{
  std::cout << "Welcome to Clover Engine" << std::endl;
  auto app = clover::createApplication();
  app->run();
  delete app;

  return 0;
}
