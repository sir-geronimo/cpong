# Define a library target for raylib
add_library(raylib STATIC IMPORTED)

# Link the executable with the raylib target defined in vendor/CMakeLists.txt
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE raylib)

# Set the location of the pre-compiled library and include directory
set_target_properties(raylib PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Link raylib and necessary frameworks on macOS
# Using INTERFACE so that anything linking to raylib also gets these frameworks
if(APPLE)
    target_link_libraries(raylib INTERFACE
            "-framework CoreVideo"
            "-framework OpenGL"
            "-framework Cocoa"
            "-framework IOKit"
            "-framework Carbon"
    )
endif()
