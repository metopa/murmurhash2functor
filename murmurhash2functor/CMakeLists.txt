cmake_minimum_required(VERSION 2.7)
project(murmurhash2functor_lib)

set(CMAKE_CXX_STANDARD 11)

add_library(murmurhash2 lib/MurmurHash2.cpp)
include_directories(include)

