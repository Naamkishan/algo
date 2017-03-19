cmake_minimum_required(VERSION 3.5)
project(AutoLoan)


set(PROJECT_BINARY "AutoLoan")

FIND_PACKAGE (Threads REQUIRED)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})

set(SOURCE_FILES AutoLoan.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})