cmake_minimum_required(VERSION 3.5)
project(LinkedList)

set(PROJECT_BINARY "LinkedList")

set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})

add_subdirectory(test)
