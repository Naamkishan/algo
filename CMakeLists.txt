cmake_minimum_required(VERSION 3.5)
project(algo)

set(PROJECT_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR})
set(BINARY_NAME algo)

set(SOURCE_FILES main.cpp)
add_executable(algo ${SOURCE_FILES})

set_property(TARGET ${BINARY_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${BINARY_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

add_subdirectory(UnionFind)