
cmake_minimum_required(VERSION 3.0)
project(longest_path)

option(BUILD_TESTS "Run tests using CATCH framework" ON)

set(CMAKE_CXX_STANDARD 11)
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
elseif (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
endif()

set (TARGET_SRC
        ${CMAKE_SOURCE_DIR}/site.cpp
        ${CMAKE_SOURCE_DIR}/succession_node.cpp
        ${CMAKE_SOURCE_DIR}/succession_graph_seq.cpp
        )

find_package(Boost)
if (NOT ${Boost_FOUND})
    message(STATUS "Boost not found. Using own...")
    set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/boost-graph")
endif()

add_executable(longest_path ${CMAKE_SOURCE_DIR}/main.cpp ${TARGET_SRC})
target_include_directories(longest_path PUBLIC ${BOOST_ROOT} ${CMAKE_SOURCE_DIR})

#Catch interface verschoeben in die untere Cmake

# test targets
if(BUILD_TESTS)
    add_subdirectory(tests)
endif(BUILD_TESTS)
