add_library(clover SHARED
    Application.cpp
    Log.cpp
)

target_precompile_headers(clover PRIVATE clvpch.hpp)

set_property(TARGET clover PROPERTY
    PCH_WARN_INVALID TRUE          # Triggers -Winvalid-pch automatically
    # PCH_INSTANTIATE_TEMPLATES TRUE # Optimizes template instantiation if supported
)

target_include_directories(clover
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(clover
    PRIVATE spdlog::spdlog
)
