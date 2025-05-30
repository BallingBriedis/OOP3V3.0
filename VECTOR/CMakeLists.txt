cmake_minimum_required(VERSION 4.0)
project(OOP2V12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(Include)
file(GLOB SOURCES "src/*.cpp")
add_executable(OOP2V12 ${SOURCES})