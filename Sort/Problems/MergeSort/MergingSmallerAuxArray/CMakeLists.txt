cmake_minimum_required(VERSION 3.5)
project(MergingSmallerAuxArray)

set(PROJECT_BINARY "MergingSmallerAuxArray")

FIND_PACKAGE (Threads REQUIRED)

link_directories($ENV{HOME}/3rdParty/libs)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

set(SOURCE_FILES test_merge_smaller_aux_array.cpp MergeSortedAuxTest.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})