set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(som
        main.cpp
        main.h
        config.h
        utils/csv_loader.cpp
        utils/csv_loader.h
        grid/rectangular.cpp
        grid/rectangular.h
        grid/grid.cpp
        grid/grid.h
        struct/node.h
        utils/math_helper.cpp
        utils/math_helper.h
        utils/trainer_helper.cpp
        utils/trainer_helper.h
        )

add_library(som_test "")

target_sources(som_test
        PRIVATE
            main.cpp
            main.h
            config.h
            utils/csv_loader.cpp
            utils/csv_loader.h
            grid/rectangular.cpp
            grid/rectangular.h
            grid/grid.cpp
            grid/grid.h
            struct/node.h
            utils/math_helper.cpp
            utils/math_helper.h
            utils/trainer_helper.cpp
            utils/trainer_helper.h
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/main.h
        )

target_include_directories(som_test
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
        )