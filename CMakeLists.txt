# CMakeLists.txt for CPong
cmake_minimum_required(VERSION 3.31)

# Set project name and version
project(CPong
        VERSION 0.1.1
        DESCRIPTION "Implementation of Pong in C++ using raylib"
        HOMEPAGE_URL "git+https://github.com/sir-geronimo/cpong"
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable target
add_executable(${CMAKE_PROJECT_NAME}
        src/main.cpp
        src/game.cpp
        src/entities/ball.cpp
        src/entities/paddle.cpp
        src/entities/cpu_paddle.cpp
)

include_directories(src/include)

# Add subdirectories for dependencies
add_subdirectory(vendor)
