cmake_minimum_required(VERSION 3.5)
project(UnionFind)

set(PROJECT_BINARY "UnionFind")

set(SOURCE_FILES main.cpp UnionFind.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})

add_subdirectory(test)
