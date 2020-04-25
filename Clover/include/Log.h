#pragma once

#include <memory>

#include "spdlog/spdlog.h"

namespace clover {

class Log
{
public:
  Log();
  ~Log();

  static void init();

  inline static std::shared_ptr< spdlog::logger >& coreLogger()
  {
    return coreLogger_;
  }

  inline static std::shared_ptr< spdlog::logger >& clientLogger()
  {
    return clientLogger_;
  }

private:
  static std::shared_ptr< spdlog::logger > coreLogger_;
  static std::shared_ptr< spdlog::logger > clientLogger_;
};

// Core log macros
#define CLV_CORE_LOG_FATAL( ... )                                              \
  ::clover::Log::coreLogger()->fatal( __VA_ARGS__ )

#define CLV_CORE_LOG_ERROR( ... )                                              \
  ::clover::Log::coreLogger()->error( __VA_ARGS__ )

#define CLV_CORE_LOG_WARN( ... )                                               \
  ::clover::Log::coreLogger()->warn( __VA_ARGS__ )

#define CLV_CORE_LOG_INFO( ... )                                               \
  ::clover::Log::coreLogger()->info( __VA_ARGS__ )

#define CLV_CORE_LOG_TRACE( ... )                                              \
  ::clover::Log::coreLogger()->trace( __VA_ARGS__ )

// Client log macros
#define CLV_CLIENT_LOG_FATAL( ... )                                            \
  ::clover::Log::clientLogger()->fatal( __VA_ARGS__ )

#define CLV_CLIENT_LOG_ERROR( ... )                                            \
  ::clover::Log::clientLogger()->error( __VA_ARGS__ )

#define CLV_CLIENT_LOG_WARN( ... )                                             \
  ::clover::Log::clientLogger()->warn( __VA_ARGS__ )

#define CLV_CLIENT_LOG_INFO( ... )                                             \
  ::clover::Log::clientLogger()->info( __VA_ARGS__ )

#define CLV_CLIENT_LOG_TRACE( ... )                                            \
  ::clover::Log::clientLogger()->trace( __VA_ARGS__ )

}  // namespace clover
