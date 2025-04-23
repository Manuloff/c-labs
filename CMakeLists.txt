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
        tasks/task7/task7_3.c
        tasks/task7/task7_4.c
        tasks/task7/task7_5.c
        tasks/task8.c
)

target_link_libraries(Example m)