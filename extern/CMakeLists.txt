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

add_library(glad STATIC glad_gl4.1/src/glad.c)
target_include_directories(glad PUBLIC glad_gl4.1/include)

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
# DearIMGUI: recommended not to build as static/shared lib
# Note: 1.92.7 works with SDL_ScaleMode. Will update to later version if fixed

CPMAddPackage(
    URI "gh:ocornut/imgui@1.92.7-docking"
    DOWNLOAD_ONLY TRUE
)

if(imgui_ADDED)
    add_library(imgui_GLFW INTERFACE)

    # Specify the required ImGui source files
    target_sources(imgui_GLFW INTERFACE
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp

        # GLFW backend with OpenGL
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    )

    # Include directories for core ImGui and its backends
    target_include_directories(imgui_GLFW INTERFACE
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
    )

    # Link ImGui to GLFW
if (MINGW)
    target_link_libraries(imgui_GLFW INTERFACE glfw opengl32)
else()
    target_link_libraries(imgui_GLFW INTERFACE glfw -lGL)
endif()

endif()

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
