#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace clover {

std::shared_ptr< spdlog::logger > Log::coreLogger_;

std::shared_ptr< spdlog::logger > Log::clientLogger_;

Log::Log() {}

Log::~Log() {}

void Log::init()
{
  // [timestamp] logger_name: log_msg
  spdlog::set_pattern( "%^[%Y-%m-%d %H:%M:%S.%e] (%L) %n: %v%$" );

  coreLogger_ = spdlog::stdout_color_mt( "CLOVER" );
  coreLogger_->set_level( spdlog::level::trace );

  clientLogger_ = spdlog::stdout_color_mt( "APP   " );
  clientLogger_->set_level( spdlog::level::trace );
}

}  // namespace clover
