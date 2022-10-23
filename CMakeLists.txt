cmake_minimum_required(VERSION 3.22)

project(shadertoy)

set(CMAKE_CXX_COMPILER "/usr/bin/g++") # remove this or change if your compiler is different
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

add_compile_options(-O3)

include_directories(common_cxx/)
include_directories(include/)

add_executable(shadertoy source/main.cxx)
target_link_libraries(shadertoy PRIVATE glfw)
