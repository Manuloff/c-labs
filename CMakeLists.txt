cmake_minimum_required(VERSION 3.30)
project(Example C)

set(CMAKE_C_STANDARD 11)
link_libraries(m)

include_directories(tasks)
include_directories(tasks/task7)

add_executable(Example main.c
        tasks/task1.c
        tasks/task2.c
        tasks/task3.c
        tasks/task4.c
        tasks/task5.c
        tasks/task6.c
        tasks/task7.c
        tasks/task7/task3_rework.c
        tasks/task8.c
        tasks/task9.c
        tasks/task7/task4_rework.c
        tasks/task7/task5_rework.c
)

target_link_libraries(Example m)