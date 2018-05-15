set(TEST_FILES
        site_test.cpp
        succession_node_test.cpp
        succession_graph_seq_test.cpp
        )

set (TARGET_H
        ../site.h
        ../succession_node.h
        ../succession_graph_seq.h
        )

set (TARGET_SRC
        ../site.cpp
        ../succession_node.cpp
        ../succession_graph_seq.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(FILE_NAME ${TEST_FILE} NAME_WE)
    add_executable(${FILE_NAME} test_main.cpp ${TEST_FILE} ${TARGET_H} ${TARGET_SRC})
    target_link_libraries(${FILE_NAME} Catch)
endforeach()

