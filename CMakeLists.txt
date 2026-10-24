cmake_minimum_required(VERSION 3.10)

project(ArchBenchs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

enable_testing()

add_subdirectory(common)
add_subdirectory(SortsBenchmark)
