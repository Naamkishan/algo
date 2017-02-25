cmake_minimum_required(VERSION 3.5)
project(TestRandomisedQueue)

set(PROJECT_BINARY "TestRandomisedQueue")

FIND_PACKAGE (Threads REQUIRED)

link_directories($ENV{HOME}/3rdParty/libs)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

include_directories(..)

set(SOURCE_FILES test_randq_main.cpp test_randq.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})
