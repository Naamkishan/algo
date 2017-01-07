cmake_minimum_required(VERSION 3.5)
project(UnionFind)

set(BINARY_NAME UnionFind)

set(SOURCE_FILES main.cpp UnionFind.cpp)
add_executable(${BINARY_NAME} ${SOURCE_FILES})
