// tasks.h
#ifndef TASKS_H
#define TASKS_H

#ifdef __cplusplus

#include <iostream>

template <typename T>
void printArray(const T* arr, int size) {
    if (size == 0) {
        std::cout << "[]";
    }

    std::cout << "[" << arr[0];

    for (int i = 1; i < size; ++i) {
        std::cout << ", " << arr[i];
    }

    std::cout << "]";
}

template <typename T>
T input(const std::string& errorMessage) {
    T value;

    while (!(std::cin >> value)) {
        std::cout << errorMessage << std::endl;
        std::cin.clear();
        std::cin.ignore(100000, '\n');
    }

    return value;
}


extern "C" {
#endif

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

void task7_1();
void task7_2();
void task7_3();

void task8_1();
void task8_2();
void task8_3();

#ifdef __cplusplus
}
#endif

#endif //TASKS_H
