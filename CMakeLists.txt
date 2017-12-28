cmake_minimum_required(VERSION 3.0)

# Options. Turn on with 'cmake -Dmyvarname=ON'
option(test "Build all tests." OFF)

# Make project directories available
set(PROJECT_NAME narmax)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

# Force static runtime libraries for msvc builds
if(MSVC)
  set(variables
  CMAKE_CXX_FLAGS_DEBUG
  CMAKE_CXX_FLAGS_RELEASE
  CMAKE_CXX_FLAGS_RELWITHDEBINFO
  CMAKE_CXX_FLAGS_MINSIZEREL)

  foreach(variable ${variables})
    if(${variable} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${variable} ${variable})
    endif()
  endforeach()
endif()

# Search for source files
file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB testSources "${CMAKE_CURRENT_SOURCE_DIR}/src/t_*.cpp")
list(FILTER sources EXCLUDE REGEX "t_.+$")

# Normal libraries and executables
message("Here are my sources: ${sources}")
message("Here are my tests: ${testSources}")

# Testing
if(test)
  if(APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
  endif(APPLE)

  add_subdirectory(lib/googletest)

  enable_testing()

# Include gtest library
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Unit tests TODO: Make narmax a library
  foreach(tsrc ${testSources})
    get_filename_component(tfname ${tsrc} NAME_WE)
    string(REGEX REPLACE ".*t_" "" tname ${tfname})
    message("Processing unit tests for ${tname}")
    add_executable(${tname} ${tsrc} ${sources})
    target_link_libraries(${tname} gtest gtest_main)
    add_test(${tname} ${tname})
  endforeach()
endif(test)
  



