add_executable(sandbox SandboxApp.cpp)

target_precompile_headers(sandbox REUSE_FROM clover)
target_link_libraries(sandbox PRIVATE clover spdlog::spdlog_header_only)
