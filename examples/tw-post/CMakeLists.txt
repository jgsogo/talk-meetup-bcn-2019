cmake_minimum_required(VERSION 2.8.12)

project(TwStream CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(libcurl)
find_package(liboauth)

add_executable(tw-post main.cpp)
target_link_libraries(tw-post PRIVATE libcurl::libcurl liboauth::liboauth)
