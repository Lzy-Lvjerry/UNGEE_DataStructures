cmake_minimum_required(VERSION 3.15)
project(UNGEE_DataStructures)

set(CMAKE_CXX_STANDARD 17)

add_executable(UNGEE_DataStructures main.cpp 1-linear-structure/stack/stack_STL.cpp 1-linear-structure/stack/Stack.h Test-File/stack_test.cpp Test-File/stack_test.h 1-linear-structure/stack/Stack_Extended.h 1-linear-structure/stack/bracket_matching.cpp 1-linear-structure/stack/stack_exec.h 1-linear-structure/queue/Queue.h 1-linear-structure/queue/Queue_Extended.h Test-File/queue_test.cpp Test-File/queue_test.h)