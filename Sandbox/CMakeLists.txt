add_executable(sandbox src/main.cpp)

target_include_directories(sandbox PRIVATE ${CLOVER_INC})
target_link_libraries(sandbox PRIVATE clover spdlog::spdlog_header_only)
