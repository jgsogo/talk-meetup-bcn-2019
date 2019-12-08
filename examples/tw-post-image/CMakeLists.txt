cmake_minimum_required(VERSION 2.8.12)

project(TwPostImage CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(libcurl)
find_package(liboauth)

add_executable(tw-post-image main.cpp base64.c)
target_link_libraries(tw-post-image PRIVATE libcurl::libcurl liboauth::liboauth)
