cmake_minimum_required(VERSION 4.1)
project(SherbinyCppLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(SherbinyCppLib main.cpp
        src/String.cpp
        include/MyString.h
        include/Vector.h
        include/Vector.tpp)

target_include_directories(SherbinyCppLib PRIVATE include)
