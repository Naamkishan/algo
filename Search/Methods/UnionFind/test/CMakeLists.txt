cmake_minimum_required(VERSION 3.5)
project(TestUnionFind)

# set(CMAKE_CXX_STANDARD 14)
set(PROJECT_BINARY "TestUnionFind")

FIND_PACKAGE (Threads REQUIRED)

include_directories(..)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

set(SOURCE_FILES main.cpp ../UnionFind.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})
