cmake_minimum_required(VERSION 3.10)
project(remove_inconsistent_sites)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall")

set (MY_SOURCE_DIR "C:/Users/Joschi/Documents/Studium/Bachelorarbeit/graph-theoretic-approach-for-MSA-bt/src")

set (TARGET_H
        site.h
        succession_node.h
        succession_graph_seq.h
        )

set (TARGET_SRC
        site.cpp
        succession_node.cpp
        succession_graph_seq.cpp
        )

include_directories( ${MY_SOURCE_DIR})

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost)

include_directories(${MY_SOURCE_DIR}/boost_1_66_0)

add_executable(remove_inconsistent_sites longest_path_runner.cpp ${TARGET_H} ${TARGET_SRC})

# Note: a target should be already defined using 'add_executable' or 'add_library'
target_link_libraries(remove_inconsistent_sites ${Boost_LIBRARIES})


