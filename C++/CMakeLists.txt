cmake_minimum_required(VERSION 2.8)
project(brainfuck)

# Building to the right place.
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/build/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/build/lib")

# Setting the C++11 flag.
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# Setting up the app.
add_executable(brainfuck src/main.cpp)

# Adding a library.
add_library(brainfuck-lib src/brainfuck.cpp
                          src/parser.cpp)

target_link_libraries(brainfuck brainfuck-lib)
