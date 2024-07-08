cmake_minimum_required(VERSION 3.22.1)

project(vml)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQIRED True)

add_library(vml INTERFACE)

target_include_directories(vml INTERFACE "${PROJECT_SOURCE_DIR}")