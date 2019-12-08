cmake_minimum_required(VERSION 2.8.12)

project(CameraApp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(camera main.cpp)
target_link_libraries(camera ${CONAN_LIBS})