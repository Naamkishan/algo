cmake_minimum_required(VERSION 3.5)
project(PriorityQueue)

set(PROJECT_BINARY "PriorityQueue")

set(SOURCE_FILES test_PriorityQueue.cpp TestPriorityQueue.cpp)

FIND_PACKAGE (Threads REQUIRED)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})