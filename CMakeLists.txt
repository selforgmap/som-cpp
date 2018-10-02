cmake_minimum_required(VERSION 3.10)
project(som)

set(CMAKE_CXX_STANDARD 14)

include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

