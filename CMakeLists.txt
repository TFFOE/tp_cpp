cmake_minimum_required(VERSION 3.16.3)
project(task1)

add_compile_options("--coverage")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include") 

file(GLOB SOURCES "src/*.c")

add_executable(task1_executable ${SOURCES})
target_link_libraries(task1_executable gcov)
