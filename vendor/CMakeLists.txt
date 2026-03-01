include(FetchContent)

# Set some raylib options before fetching
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(BUILD_CUSTOM_RES_ICONS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
)

FetchContent_MakeAvailable(raylib)

# Link the executable with the raylib target defined in raylib's own CMakeLists.txt
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE raylib)

