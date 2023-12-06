cmake_minimum_required(VERSION 3.0)
project(OpenAddressHashing)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include)

add_executable(OpenAddressHashing
        src/main.cpp
        src/HashTable.cpp)
