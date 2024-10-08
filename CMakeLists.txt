cmake_minimum_required(VERSION 3.29)
project(test_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_2
        src/Solution.cpp
        include/Solution.h
        LeetCode/LeetCodeTasks.cpp
        LeetCode/LeetCodeTasks.h
        main.cpp)
