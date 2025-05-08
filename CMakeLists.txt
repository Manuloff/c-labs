cmake_minimum_required(VERSION 3.16)  # более совместимая минимальная версия
project(Example LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Example
        main.c
        tasks/task1.c
        tasks/task2.c
        tasks/task3.c
        tasks/task4.c
        tasks/task5.c
        tasks/task6.c
        tasks/task7.c
        tasks/task7/task7_3.c
        tasks/task7/task7_4.c
        tasks/task7/task7_5.c
        tasks/task8.cpp
        tasks/task8/task8_3.cpp
        tasks/task8/task8_4.cpp
)

target_include_directories(Example PRIVATE
        tasks
        tasks/task7
        tasks/task8
)

target_link_libraries(Example PRIVATE m)
