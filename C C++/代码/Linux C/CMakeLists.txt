cmake_minimum_required(VERSION 3.13)
project(Linux_C)

set(CMAKE_CXX_STANDARD 11)

add_executable(Linux_C main.cpp common.cpp common.h)

find_package(Threads REQUIRED)
target_link_libraries(Linux_C Threads::Threads)