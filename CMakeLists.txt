cmake_minimum_required(VERSION 3.7)

project(euler CXX)


set(CMAKE_CXX_STANDARD 20)
# dependencies
message(STATUS "RANGE_V3_INCLUDE_DIR " $ENV{RANGE_V3_INCLUDE_DIR})
set(range-v3_INCLUDE_DIR $ENV{RANGE_V3_INCLUDE_DIR})
add_library(range-v3 INTERFACE IMPORTED)
set_property(TARGET range-v3
  PROPERTY
    INTERFACE_INCLUDE_DIRECTORIES ${range-v3_INCLUDE_DIR}
)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++experimental")

find_package(Boost)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)

