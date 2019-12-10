cmake_minimum_required(VERSION 2.8.12)

project(helloapp CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_PATH})

find_package(fmt)
find_package(hellolib)

add_executable(helloapp main.cpp)
target_link_libraries(helloapp PRIVATE fmt::fmt hellolib::hellolib)
