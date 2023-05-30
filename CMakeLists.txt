cmake_minimum_required(VERSION 3.0)

project(callib)

# settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include .cpp .h
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/graph)
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# exe
add_executable(callib ${SOURCE_FILES})

add_library(lib SHARED ${SOURCE_FILES})
set_target_properties(lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dll"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dll"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dll"
)