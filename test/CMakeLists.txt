add_executable(
        unit_tests
        main_test.cpp
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
            ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)
