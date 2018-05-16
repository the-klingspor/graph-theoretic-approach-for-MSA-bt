cmake_minimum_required(VERSION 3.10)
project(longest_path)

##########################
#        OPTIONS         #
##########################

option(BUILD_TESTS "Run tests using CATCH framework" ON)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall")

set (TARGET_H
        site.h
        succession_node.h
        succession_graph_seq.h
        )

set (TARGET_SRC
        site.cpp
        succession_node.cpp
        succession_graph_seq.cpp)

set(Boost_NO_SYSTEM_PATHS TRUE)
if (Boost_NO_SYSTEM_PATHS)
    set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/boost_1_66_0")
    set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/include")
    set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/lib")
endif (Boost_NO_SYSTEM_PATHS)
find_package(Boost)
include_directories(${BOOST_ROOT})

add_executable(longest_path main.cpp ${TARGET_H} ${TARGET_SRC})

# Note: a target should be already defined using 'add_executable' or 'add_library'
target_link_libraries(longest_path ${Boost_LIBRARIES})

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/tests})

# test targets
if(BUILD_TESTS)
    add_subdirectory(tests)
endif(BUILD_TESTS)
