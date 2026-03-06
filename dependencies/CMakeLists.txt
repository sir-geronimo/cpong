# =================
# Raylib
# =================

set(RAYLIB_VERSION 5.5 CACHE STRING "Version of raylib to use")
set(BUILD_EXAMPLES OFF CACHE BOOL "Whether to build raylib examples" FORCE)

# Find or Fetch package in case it's not available on the system
find_package(raylib ${RAYLIB_VERSION} QUIET)
# If we cannot find locally available raylib
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
    endif ()
endif ()


# Link the executable with the raylib target defined in raylib's own CMakeLists.txt
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE raylib)
