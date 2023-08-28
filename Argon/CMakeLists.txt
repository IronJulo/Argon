cmake_minimum_required(VERSION 3.16)
project(Argon)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Argon main.cpp src/Argument.cpp src/Processor.cpp)