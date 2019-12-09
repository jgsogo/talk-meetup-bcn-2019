cmake_minimum_required(VERSION 2.8.12)

project(CameraApp CXX)
find_package(opencv)

add_executable(camera main.cpp)
target_link_libraries(camera opencv::opencv)
set_target_properties(camera PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
