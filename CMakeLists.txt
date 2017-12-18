cmake_minimum_required(VERSION 3.0)
project(narmax)

#########################
# Search for source files

file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB testSources "${CMAKE_CURRENT_SOURCE_DIR}/src/t_*.cpp")
list(FILTER sources EXCLUDE REGEX "t_.+$")

#################################
# Download and install GoogleTest

include(ExternalProject)
ExternalProject_Add(gtest
  # URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
  GIT_REPOSITORY https://github.com/google/googletest.git
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  INSTALL_COMMAND ""
  )
ExternalProject_Get_Property(
  gtest
  source_dir
  binary_dir
  )

##################
# Define test executable
add_executable(AllTest ${sources} ${testSources})

##################
# Configure it to use GTest
add_dependencies(AllTest gtest)
include_directories(${source_dir}/include)
target_link_libraries(AllTest ${binary_dir}/libgtest.a)
target_link_libraries(AllTest ${binary_dir}/libgtest_main.a)

#########################
# Making the test runnable
enable_testing()
add_test(
  NAME    AllTest
  COMMAND AllTest
  )

