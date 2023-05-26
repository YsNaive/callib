cmake_minimum_required(VERSION 3.0)

project(callib)

# settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find .cpp .h
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

# include
include_directories(include)

# exe
add_executable(callib ${HEADER_FILES} ${SOURCE_FILES})