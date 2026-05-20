cmake_minimum_required(VERSION 4.0)
project(project_C)

set(CMAKE_CXX_STANDARD 14)

include_directories(code/practice/practice_4)

add_executable(project_C
        code/practice/practice_4/CMakeLists.txt
        code/practice/practice_4/main.c
        code/practice/practice_4/triangle.c
        code/practice/practice_4/triangle.h)
