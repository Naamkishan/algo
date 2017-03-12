cmake_minimum_required(VERSION 3.5)
project(CollinearPoints)

# setup the data dir for the test cases
# set(ENV{PROJECT_DATA_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/data)
set(ENV{PROJECT_DATA_DIR} "${CMAKE_CURRENT_SOURCE_DIR}")

# Boost specific -- This only includes the boost include directory
find_package(Boost COMPONENTS system filesystem REQUIRED)
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


set(ENV{GTEST_COLOR} "1")

set(PROJECT_BINARY "CollinearPoints")

FIND_PACKAGE (Threads REQUIRED)

link_directories($ENV{HOME}/3rdParty/libs)

list(APPEND LIBRARIES "libgtest.a")
list(APPEND LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
list(APPEND LIBRARIES ${Boost_FILESYSTEM_LIBRARY})
list(APPEND LIBRARIES ${Boost_SYSTEM_LIBRARY})


set(SOURCE_FILES test_collinear_points.cpp brute_collinear.cpp TestFastCollinear.cpp)
add_executable(${PROJECT_BINARY} ${SOURCE_FILES})
target_link_libraries(${PROJECT_BINARY} ${LIBRARIES})