//
// Created by MrJFG on 08.05.2025.
//

#include <iostream>
#include "../tasks.h"

using namespace std;

// Нахождение максимального значения
template <typename T>
T maxInArr(const T* arr, const int size) {
    if (size <= 0) {
        return 0;
    }

    T max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Нахождение минимального значения
template <typename T>
T minInArr(const T* arr, const int size) {
    if (size <= 0) {
        return 0;
    }

    T min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

// Сумма чисел
template <typename T>
T sumInArr(const T* arr, const int size) {
    if (size == 0) {
        return 0;
    }

    T sum = arr[0];

    for (int i = 1; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

// Среднее арифметическое в массиве
template <typename T>
double averageInArr(const T* arr, const int size) {
    return ((double) sumInArr(arr, size)) / size;
}

// Получение индекса элемента в массиве
template <typename T>
int indexOf(const T* arr, const int size, const T searchable) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchable) {
            return i;
        }
    }

    return -1; // Если элемент не найден
}

template <typename T>
void process(const T* arr, int size, const string& text) {
    cout << "Работаем с " << text << ": ";
    printArray(arr, size);
    cout << endl;

    cout << "\tМаксимальное значение: " << maxInArr(arr, size) << endl;
    cout << "\tМинимальное значение: " << minInArr(arr, size) << endl;
    cout << "\tСумма значений: " << sumInArr(arr, size) << endl;
    cout << "\tСреднее арифметическое: " << averageInArr(arr, size) << endl;
    cout << "\tИндекс 5 элемента в массиве: " << indexOf(arr, size, arr[4]) << endl;
}

void task8_3() {
    int intArray[] = {0, 9, 1, 8, 2, 7, 3, 6, 4, 5};
    double doubleArray[] = {-10.5, 0.0, 3.14159, 42.42, -7.3};
    float floatArray[] = {1.0f, 2.5f, 3.5f, -4.0f, 0.0f};

    process(intArray, sizeof(intArray) / sizeof(int), "массивом целых чисел");
    process(doubleArray, sizeof(doubleArray) / sizeof(double), "массивом вещественных чисел (double)");
    process(floatArray, sizeof(floatArray) / sizeof(float), "массивом вещественных чисел (float)");

}