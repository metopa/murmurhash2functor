cmake_minimum_required(VERSION 2.7)
project(murmurhash2functor_example)

set(CMAKE_CXX_STANDARD 11)

include_directories(../include)
add_executable(main main.cpp)
target_link_libraries(main murmurhash2)
