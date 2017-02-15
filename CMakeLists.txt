cmake_minimum_required(VERSION 3.5)
project(algo)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

option(USE_STATIC_BOOST "Build with static BOOST libraries instead of dynamic" YES)

include_directories($ENV{HOME}/3rdParty/include include)

set(ENV{GTEST_COLOR} "1")

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Boost specific -- This only includes the boost include directory
find_package(Boost)
if(Boost_FOUND)
    message(STATUS "Found Boost version ${Boost_VERSION}")
    set(Boost_USE_STATIC_LIBS ${USE_STATIC_BOOST})
    set(Boost_USE_MULTITHREADED ON)
    unset(Boost_INCLUDE_DIR CACHE)
    unset(Boost_LIBRARY_DIRS CACHE)
    if(USE_STATIC_BOOST)
        message(STATUS "Linking against boost static libraries")
    else(NOT USE_STATIC_BOOST)
        message(STATUS "Linking against boost dynamic libraries")
    endif()
    include_directories(${Boost_INCLUDE_DIRS})
endif()

# set_property(TARGET ${BINARY_NAME} PROPERTY CXX_STANDARD 14)
# set_property(TARGET ${BINARY_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

add_subdirectory(DS)
add_subdirectory(Search)
add_subdirectory(Sort)
add_subdirectory(Problems)

