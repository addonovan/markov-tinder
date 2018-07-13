cmake_minimum_required(VERSION 3.10)
project(markov)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)
add_executable(markov ${HEADERS} ${SOURCES})
