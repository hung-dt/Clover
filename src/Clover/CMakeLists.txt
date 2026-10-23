set(CLOVER_SOURCES
    Application.cpp
    Log.cpp
)

if(WIN32)
    message(STATUS "Windows platform")
    list(APPEND CLOVER_SOURCES Platform/Win/WindowWin.cpp)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Linux platform")
    # list(APPEND CLOVER_SOURCES Platform/Linux/WindowLinux.cpp)
endif()

add_library(clover SHARED ${CLOVER_SOURCES})

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
    PUBLIC spdlog::spdlog glfw
)
