cmake_minimum_required(VERSION 3.0)
project(SM_Interpreter)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(SM_Interpreter main.cpp)

target_link_libraries(SM_Interpreter study-machine-r study-machine-z)

add_subdirectory(src/Operations)
add_subdirectory(src/SM-Z)
add_subdirectory(src/SM-R)
add_subdirectory(src/utils)
