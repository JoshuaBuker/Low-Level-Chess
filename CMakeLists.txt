# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(game VERSION 1.0)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Add the include directories
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/gameLogic/header
    ${PROJECT_SOURCE_DIR}/util/header
)

# Add the source files
set(SOURCE_FILES
    game.c
    gameLogic/source/board.c
    util/source/util.c
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Set the compiler flags (mimicking your CFLAGS in the Makefile)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)

# Custom clean target to remove object files
add_custom_target(clean-obj
    COMMAND ${CMAKE_COMMAND} -E rm -f
    ${CMAKE_BINARY_DIR}/*.o
    ${CMAKE_BINARY_DIR}/gameLogic/source/*.o
    ${CMAKE_BINARY_DIR}/util/source/*.o
    COMMENT "Cleaning object files"
)

# Custom clean target for removing the executable and object files
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -f ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E rm -f ${CMAKE_BINARY_DIR}/*.o
    COMMAND ${CMAKE_COMMAND} -E rm -f ${CMAKE_BINARY_DIR}/gameLogic/source/*.o
    COMMAND ${CMAKE_COMMAND} -E rm -f ${CMAKE_BINARY_DIR}/util/source/*.o
    COMMENT "Cleaning all built files"
)
