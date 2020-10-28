cmake_minimum_required(VERSION 3.16.3)
project(task2)
SET (BASIC_EXE task2)

# Проверка покрытия тестами
#add_compile_options("--coverage")

# Отключение assert
# add_compile_options("-DNDEBUG")

add_compile_options("-Wall"  "-Werror" "-Wpedantic")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/project/include")

file(GLOB SOURCES "project/src/main.c")
# file(GLOB TEST_SRC_FILES "gtests/tests.cpp" "gtests/main.cpp")

# Подключение динамической или статической библиотеки в зависимости от параметра DYN
add_subdirectory(project_libs)

add_executable(${BASIC_EXE} ${SOURCES})
target_link_libraries(${BASIC_EXE} lib)

option(BUILD_TESTS "Build all tests." OFF)
if (BUILD_TESTS)
  add_subdirectory(ext/gtest)

  enable_testing()

  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests ${TEST_SRC_FILES} ${TEST_FUNCTIONS_FILES})
  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(UnitTests runUnitTests)

  set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.travis/cmake)
  if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage runUnitTests coverage)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
  endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

endif() 