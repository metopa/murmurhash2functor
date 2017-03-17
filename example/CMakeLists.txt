cmake_minimum_required(VERSION 3.6)
project(murmurhash2functor_example)

set(CMAKE_CXX_STANDARD 11)

include_directories(../murmurhash2functor/include)
add_executable(main main.cpp)
target_link_libraries(main murmurhash2)
