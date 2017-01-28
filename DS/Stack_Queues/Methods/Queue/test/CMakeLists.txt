cmake_minimum_required(VERSION 3.5)
project(TestQueue)

set(PROJECT_BINARY "TestQueue")

FIND_PACKAGE (Threads REQUIRED)

include_directories($ENV{HOME}/3rdParty/include ..)
link_directories($ENV{HOME}/3rdParty/libs)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})
