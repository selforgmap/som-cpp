set(BOOST_ROOT "/usr/local/Cellar/boost/1.67.0_1")

find_package(Boost)


if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

cmake_minimum_required(VERSION 3.12)
project(som)

set(CMAKE_CXX_STANDARD 14)

add_executable(som src/main.cpp src/config.h src/utils/csv_loader.cpp src/utils/csv_loader.h src/main.h src/core/trainer.cpp src/core/trainer.h src/topology/rectangular.cpp src/topology/rectangular.h src/struct/position.h src/utils/math_helper.cpp src/utils/math_helper.h)