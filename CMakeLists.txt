cmake_minimum_required(VERSION 3.12)
project(som)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()
add_subdirectory(test)

add_executable(som src/main.cpp src/config.h src/utils/csv_loader.cpp src/utils/csv_loader.h src/main.h src/topology/rectangular.cpp src/topology/rectangular.h src/struct/position.h src/utils/math_helper.cpp src/utils/math_helper.h)
