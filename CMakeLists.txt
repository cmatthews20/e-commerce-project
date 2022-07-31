cmake_minimum_required(VERSION 3.22)
project(Projects)

set(CMAKE_CXX_STANDARD 23)

add_executable(Projects main.cpp linkedList.cpp linkedList.h dll.cpp dll.h stack.cpp stack.h queue.cpp queue.h helper.cpp)
