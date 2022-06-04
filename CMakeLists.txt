cmake_minimum_required(VERSION 3.13)  # CMake version check
project(tetris)                       # Create project "tetris"
set(CMAKE_CXX_STANDARD 11)            # Enable c++14 standard

# Add sources files.
set(SOURCE_FILES
    main.cpp
    Tetris.cpp 
    visual_elements/Field.cpp
    visual_elements/figure/Figure.cpp
    visual_elements/figure/concrete_figure/Stick.cpp)

# Add headers files.
set(HEADER_FILES
    Tetris.h
    visual_elements/Field.h
    visual_elements/figure/Figure.h
    visual_elements/figure/concrete_figure/Stick.h)

# Add subdirectory.
set(DIRS
    visual_elements
    visual_elements/figure
    visual_elements/figure/concrete_figure)

# Add executable target.
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${DIRS})
