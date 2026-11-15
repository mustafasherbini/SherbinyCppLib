cmake_minimum_required(VERSION 4.1)
project(SherbinyCppLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(SherbinyCppLib main.cpp
        src/Srtring.cpp
        include/MyString.h
        src/Vector.cpp
        include/Vector.h
)

target_include_directories(SherbinyCppLib PRIVATE include)
