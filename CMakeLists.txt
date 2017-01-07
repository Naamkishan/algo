cmake_minimum_required(VERSION 3.6)
project(algo)

set(SOURCE_FILES main.cpp)
add_executable(algo ${SOURCE_FILES})

set_property(TARGET algo PROPERTY CXX_STANDARD 14)
set_property(TARGET algo PROPERTY CXX_STANDARD_REQUIRED ON)