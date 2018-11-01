set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Source files
file(GLOB SRC_FILES
        main.cpp
        main.h
        init.h
        core/som.cpp
        core/som.h
        utils/csv_loader.cpp
        utils/csv_loader.h
        grids/rectangular.cpp
        grids/rectangular.h
        core/grid.cpp
        core/grid.h
        struct/node.h
        helpers/trainer_helper.cpp
        helpers/trainer_helper.h
        helpers/neighborhood.cpp
        helpers/neighborhood.h
        helpers/learning_rate.cpp
        helpers/learning_rate.h
        struct/config.h
        utils/arg_parser.cpp
        utils/arg_parser.h)

# Create the main executable
add_executable(som ${SRC_FILES})

# Create a shared library
add_library(libsom ${SRC_FILES} utils/arg_parser.cpp utils/arg_parser.h)
set_target_properties(libsom PROPERTIES PREFIX "")
target_include_directories(libsom PUBLIC ${CMAKE_CURRENT_LIST_DIR})