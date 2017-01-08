cmake_minimum_required(VERSION 3.5)
project(BinarySearch)

set(PROJECT_BINARY "BinarySearch")

set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})

add_subdirectory(test)
