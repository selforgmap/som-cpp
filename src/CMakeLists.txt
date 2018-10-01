add_library(som_test "")

target_sources(
        som_test
        PRIVATE
            main.cpp
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/main.h
)

target_include_directories(
        som_test
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
)