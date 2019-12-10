cmake_minimum_required(VERSION 3.10.2)
project(raytracer)

include_directories("external")

file(GLOB SOURCES "src/*.cpp")

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(OpenMP REQUIRED)

add_executable(raytracer ${SOURCES})

target_link_libraries(raytracer Eigen3::Eigen)
target_link_libraries(raytracer ${OpenCV_LIBS})
target_link_libraries(raytracer OpenMP::OpenMP_CXX)