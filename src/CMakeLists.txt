cmake_minimum_required(VERSION 3.10)
project(src)

set(CMAKE_CXX_STANDARD 11)

add_executable(src longest_path_runner.cpp)

target_include_directories(src PRIVATE ${C/Users/Joschi/Documents/Studium/Bachelorarbeit/graph-theoretic-approach-for-MSA-bt/src})

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost)

include_directories(${C/Users/Joschi/Documents/Programmieren/boost_1_66_0/boost})
# Note: a target should be already defined using 'add_executable' or 'add_library'
target_link_libraries(src ${Boost_LIBRARIES})


