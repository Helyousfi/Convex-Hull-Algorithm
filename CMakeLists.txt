cmake_minimum_required(VERSION 3.10)
project(ConvexHull)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(convex_hull src/main.cpp src/point.cpp src/convex_hull.cpp)
