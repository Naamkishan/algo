cmake_minimum_required(VERSION 3.5)
project(gcd)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_BINARY "gcd")

set(SOURCE_FILES gcd.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})

