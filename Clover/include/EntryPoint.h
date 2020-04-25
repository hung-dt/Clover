#pragma once

#include "Clover.h"

#include <iostream>

int main( int argc, char const* argv[] )
{
  clover::Log::init();

  CLV_CORE_LOG_WARN( "Initialized Log!" );
  CLV_CLIENT_LOG_INFO( "Hello '{}' from {}!", "Hung Do", "CLOVER ENGINE" );

  auto app = clover::createApplication();
  app->run();
  delete app;

  return 0;
}
