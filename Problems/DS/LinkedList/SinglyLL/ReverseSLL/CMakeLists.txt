cmake_minimum_required(VERSION 3.5)
project(ReverseSinglyLinkedList)

set(PROJECT_BINARY "ReverseSinglyLinkedList")

set(BOOST_VERSION "1.63.0")
option(USE_STATIC_BOOST "Build with static BOOST libraries instead of dynamic" ON)

find_package(Boost ${BOOST_VERSION} REQUIRED COMPONENTS system filesystem)
if(Boost_FOUND)
    message(STATUS "Found Boost version ${Boost_VERSION}")
    set(Boost_USE_STATIC_LIBS ${USE_STATIC_BOOST})
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_STATIC_RUNTIME OFF)
    unset(Boost_INCLUDE_DIR CACHE)
    unset(Boost_LIBRARY_DIRS CACHE)
    if(USE_STATIC_BOOST)
        message(STATUS "Linking against boost static libraries")
    else(USE_STATIC_BOOST)
        message(STATUS "Linking against boost dynamic libraries")
    endif()
    include_directories(${Boost_INCLUDE_DIRS})
else(NOT Boost_FOUND)
    message(STATUS "Unable to lookup boost")
endif()

FIND_PACKAGE (Threads REQUIRED)

link_directories($ENV{HOME}/3rdParty/libs)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
list(APPEND LIBRARIES ${Boost_LIBRARIES})

set(SOURCE_FILES Test_RevSinglyLL.cpp Test_ReverseLinkedList.cpp reverse_sll.h)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})
