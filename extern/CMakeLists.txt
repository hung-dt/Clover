#------------------------------------------------------------------------------
# External C/C++ libraries using CPM.cmake
#------------------------------------------------------------------------------

include(CPM)

#------------------------------------------------------------------------------
# spdlog as shared lib

CPMAddPackage(
    URI "gh:gabime/spdlog@1.16.0"
    OPTIONS
        "SPDLOG_BUILD_SHARED ON"
)

#------------------------------------------------------------------------------
# glad v1

add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

#------------------------------------------------------------------------------
# glm

CPMAddPackage("gh:g-truc/glm#1.0.3")

#------------------------------------------------------------------------------
# glfw as shared lib

CPMAddPackage(
    NAME glfw
    GITHUB_REPOSITORY glfw/glfw
    GIT_TAG 3.5.1
    OPTIONS
        "GLFW_LIBRARY_TYPE SHARED"
        "GLFW_BUILD_DOCS OFF"
        "GLFW_BUILD_TESTS OFF"
        "GLFW_BUILD_EXAMPLES OFF"
)

#------------------------------------------------------------------------------
# SDL3

CPMAddPackage(
    URI "gh:libsdl-org/SDL#release-3.4.14"
    OPTIONS
        "SDL_SHARED ON"
        "SDL_TESTS OFF"
        "SDL_DISABLE_INSTALL ON"
)

if (BUILD_TESTS)

#------------------------------------------------------------------------------
# doctest
CPMAddPackage("gh:doctest/doctest@2.4.12")

#------------------------------------------------------------------------------
# nanobench
CPMAddPackage(
    URI "gh:martinus/nanobench@4.3.11"
    GIT_SHALLOW TRUE
)

endif()
