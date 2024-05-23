cmake_minimum_required(VERSION 3.4)
project(webserv)

set(CMAKE_BUILD_TYPE Debug)
include_directories(include)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(server ${SOURCES})
