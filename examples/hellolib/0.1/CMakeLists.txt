cmake_minimum_required(VERSION 3.1)
project(hellolib CXX)

file(GLOB SOURCES
        src/hello.cpp
        )
file(GLOB HEADERS
        include/hellolib/hello.h
        )

find_package(fmt)

add_library(hellolib ${SOURCES} ${HEADERS})
target_link_libraries(hellolib PUBLIC fmt::fmt)
target_include_directories(
        hellolib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
