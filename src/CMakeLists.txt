set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(som
        main.cpp
        main.h
        config.h
        core/trainer.cpp
        core/trainer.h
        utils/csv_loader.cpp
        utils/csv_loader.h
        grids/rectangular.cpp
        grids/rectangular.h
        core/grid.cpp
        core/grid.h
        struct/node.h
        helpers/trainer_helper.cpp
        helpers/trainer_helper.h
        helpers/neighbourhood_function.cpp helpers/neighbourhood_function.h helpers/learning_rate.cpp helpers/learning_rate.h struct/config.h)

add_library(som_test "")

target_sources(som_test
        PRIVATE
        main.cpp
        main.h
        config.h
        core/trainer.cpp
        core/trainer.h
        utils/csv_loader.cpp
        utils/csv_loader.h
        grids/rectangular.cpp
        grids/rectangular.h
        core/grid.cpp
        core/grid.h
        struct/node.h
        helpers/trainer_helper.cpp
        helpers/trainer_helper.h

        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/main.h
        )

target_include_directories(som_test
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
        )