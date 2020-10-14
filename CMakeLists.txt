cmake_minimum_required(VERSION 3.16.3)
project(task1)

add_compile_options("--coverage" "-DNDEBUG")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include") 

file(GLOB SOURCES "src/*.cpp" "gtests/tests.cpp")

find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest_main)

add_executable(task1 ${SOURCES})
target_link_libraries(task1 gcov ${GTEST_LDFLAGS})
add_compile_options(PUBLIC ${GTEST_CFLAGS})

include(CTest)
add_test(first_test task1)