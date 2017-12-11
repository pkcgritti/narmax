cmake_minimum_required(VERSION 3.0)
project(narmax)

# Prepare "Catch" library for other executable
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Make test executable
set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp)
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests Catch)


