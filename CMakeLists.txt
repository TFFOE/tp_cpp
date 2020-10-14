cmake_minimum_required(VERSION 3.16.3)
project(task1)

#add_compile_options("--coverage")
add_compile_options("-DNDEBUG")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include") 

file(GLOB SOURCES "src/*.cpp")
file(GLOB TEST_SRC_FILES "gtests/tests.cpp")

#find_package(PkgConfig)
#pkg_search_module(GTEST REQUIRED gtest_main)


#target_link_libraries(task1 gcov ${GTEST_LDFLAGS})
#add_compile_options(PUBLIC ${GTEST_CFLAGS})

option(BUILD_TESTS "Build all tests." OFF) # Makes boolean 'test' available.

if (BUILD_TESTS)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(ext/gtest)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests ${TEST_SRC_FILES})
  add_executable(task1 ${SOURCES})

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(UnitTests runUnitTests)

endif()