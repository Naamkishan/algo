cmake_minimum_required(VERSION 3.5)
project(algo)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 14)

include_directories($ENV{HOME}/3rdParty/include)

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# set_property(TARGET ${BINARY_NAME} PROPERTY CXX_STANDARD 14)
# set_property(TARGET ${BINARY_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

add_subdirectory(DS)
add_subdirectory(Search)
add_subdirectory(Sort)

