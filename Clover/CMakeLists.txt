add_library(clover
    include/Clover.h
    include/Core.h
    include/Application.h
    src/Core.cpp
    src/Application.cpp
)
target_include_directories(clover
    PRIVATE src
    PUBLIC include
)