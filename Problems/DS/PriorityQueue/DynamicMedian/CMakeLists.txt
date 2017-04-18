cmake_minimum_required(VERSION 3.5)
project(DynamicMedian)

set(PROJECT_BINARY "DynamicMedian")

FIND_PACKAGE (Threads REQUIRED)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
list(APPEND LIBRARIES ${Boost_LIBRARIES})

set(SOURCE_FILES DynamicMedian_Test.cpp TestDynamicMedian.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})
