cmake_minimum_required(VERSION 3.10)
project(ConvexHull VERSION 1.0.0 LANGUAGES C CXX)

# Create variables
set(EXECUTABLE_NAME "convex_hull")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Compiler must implement all C++17 features
set(CMAKE_CXX_EXTENSIONS OFF)       # Don't use extensions

# Include directories for your project
include_directories(include)

# Include directories for SFML
include_directories(src-smfl/include)

# Add SFML library paths
link_directories(src-smfl/lib)

# Add executable
add_executable(${EXECUTABLE_NAME} app/main.cpp src/point.cpp src/convex_hull.cpp)

# Link SFML libraries
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)

# Copy SFML DLLs to the executable directory
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/src-smfl/bin"
        $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>)
