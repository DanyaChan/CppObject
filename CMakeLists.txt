cmake_minimum_required(VERSION 3.16)
project(Object)

set(CMAKE_CXX_STANDARD 17)

file(GLOB COMMON_SRC Sources/*.cpp)
set(SOURCE ${COMMON_SRC})
add_compile_options(-ftemplate-depth=50000)

add_executable(Object main.cpp ${SOURCE})