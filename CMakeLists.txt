cmake_minimum_required(VERSION 4.1)
project(SherbinyCppLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(SherbinyCppLib main.cpp
        src/String.cpp
        include/MyString.h
        include/Vector.h
        include/Stack.h
        include/TwoStackQueue.h
        include/UniquePtr.h)

target_include_directories(SherbinyCppLib PRIVATE include)
