set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(../cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()

add_executable(
        unit_tests
        main_test.cpp
        grid_test.cpp
        ../src/helpers/neighborhood.cpp ../src/helpers/neighborhood.h)

target_link_libraries(
        unit_tests
        gtest_main
        libsom
        )

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/bin/unit_tests
)
