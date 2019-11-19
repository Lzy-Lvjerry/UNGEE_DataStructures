cmake_minimum_required(VERSION 3.15)
project(UNGEE_DataStructures)

set(CMAKE_CXX_STANDARD 17)

add_executable(UNGEE_DataStructures main.cpp 1-linear-structure/stack/stack_STL.cpp 1-linear-structure/stack/Stack.cpp 1-linear-structure/stack/Stack.h Test-File/stack_test.cpp Test-File/stack_test.h 1-linear-structure/stack/Stack_Extended.h)