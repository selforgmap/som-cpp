set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
        unit_tests
        main_test.cpp
        grid_test.cpp
        )

target_link_libraries(
        unit_tests
        gtest_main
        som_test
        )

add_test(
        NAME
            unit
        COMMAND
            ${CMAKE_BINARY_DIR}/bin/unit_tests
        )
