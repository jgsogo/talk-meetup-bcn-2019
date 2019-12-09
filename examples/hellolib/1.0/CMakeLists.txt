cmake_minimum_required(VERSION 3.1)
project(hellolib CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
        src/hello.cpp
        )
file(GLOB HEADERS
        include/hellolib/hello.h
        )

find_package(fmt)

add_library(hellolib ${SOURCES} ${HEADERS})
set_target_properties(hellolib PROPERTIES PUBLIC_HEADER ${HEADERS})
target_link_libraries(hellolib PUBLIC fmt::fmt)
target_include_directories(
        hellolib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS hellolib
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include/hellolib)
