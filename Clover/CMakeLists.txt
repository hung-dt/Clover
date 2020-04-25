add_library(clover
    include/Clover.h
    include/Core.h
    include/Application.h
    include/Log.h
    src/Core.cpp
    src/Application.cpp
    src/Log.cpp
)
target_include_directories(clover
    PRIVATE src
    PUBLIC include
)
target_link_libraries(clover
    PRIVATE spdlog::spdlog
)