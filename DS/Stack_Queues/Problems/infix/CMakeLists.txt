cmake_minimum_required(VERSION 3.5)
project(infix)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_BINARY "infix")


FIND_PACKAGE (Threads REQUIRED)

link_directories($ENV{HOME}/3rdParty/libs)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

set(SOURCE_FILES infix.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})

