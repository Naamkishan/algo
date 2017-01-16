cmake_minimum_required(VERSION 3.5)
project(infix)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_BINARY "infix")

include_directories(../Include)

set(SOURCE_FILES infix.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})

