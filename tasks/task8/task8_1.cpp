//
// Created by nikita on 03.05.2025.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include "../tasks.h"

using namespace std;

template <typename T>
T* getArrayFromInput(int& size) {
    cout << "Введите размерность массива: ";
    size = input<int>("Неподходящее значение для размера массива");

    if (size < 1) {
        cout << "Некорректное значение размера массива (" << size << "), принято 3" << endl;
        size = 3;
    }

    T* arr = new T[size];

    cout << "Введите " << size << " элементов: " << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". ";
        arr[i] = input<T>("Неверный ввод, повторите ещё раз.");
    }

    return arr;
}

template <typename T>
T* getArrayFromFile(int& size) {
    ifstream file("../data/task8_1.txt");
    if (!file.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        size = 0;
        return nullptr;
    }

    T temp;
    size = 0;

    while (file >> temp) {
        size++;
    }

    if (size == 0) {
        cout << "Файл пустой или содержит некорректные данные" << endl;
        return nullptr;
    }

    file.clear();
    file.seekg(0, ios::beg);

    T* arr = new T[size];
    for (int i = 0; i < size; i++) {
        file >> arr[i];
    }

    return arr;
}

template <typename T>
int countBetweenElements(const T* arr, const int size, const T A, const T B) {
    if (arr == nullptr || size < 0) {
        return -1;
    }

    int count = 0;

    for (int i = 0; i < size; i++) {
        const T e = arr[i];

        if (e < A || e > B) {
            continue;
        }

        count++;
    }

    return count;
}

template <typename T>
int maxElementIndex(const T* arr, const int size) {
    if (size <= 0 || arr == nullptr) {
        return -1;
    }

    int maxIndex = 0;
    float maxValue = arr[0];

    for (int i = 1; i < size; i++) {
        float element = arr[i];

        if (maxValue > element) {
            continue;
        }

        maxValue = element;
        maxIndex = i;
    }

    return maxIndex;
}

template <typename T>
T sumAfterIndex(const T* arr, const int size, const int index) {
    if (arr == nullptr || index < -1 || index >= size) {
        return 0;
    }

    float sum = 0;

    for (int i = index + 1; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

template <typename T>
void sortByAbsDesc(T* arr, const int size) {
    if (arr == nullptr || size == 0) {
        return;
    }

    // Сортировка простого выбора
    for (int k = 0; k < size - 1; k++) {
        T value = arr[k];
        int index = k;

        for (int i = k + 1; i < size; i++) {
            const T element = arr[i];

            if (abs(value) > abs(element)) {
                continue;
            }

            value = element;
            index = i;
        }

        arr[index] = arr[k];
        arr[k] = value;
    }
}

template <typename T>
void _task8_1() {
    cout << "Общее задание" << endl;
    cout << "\tИсходные данные для всех вариантов — n вещественных величин. При написании" << endl;
    cout << "\tпрограмм можно использовать как динамические, так и не-динамические массивы." << endl;
    cout << endl;

    cout << "Задание варианта 13:" << endl;
    cout << "\t1. Найти количество элементов массива, лежащих в диапазоне от А до В." << endl;
    cout << "\t2. Найти сумму элементов массива, расположенных после максимального элемента." << endl;
    cout << "\t3. Упорядочить элементы массива по убыванию модулей элементов." << endl;
    cout << endl;

    while (true) {
        cout << "Можно использовать заранее заготовленный массив из файла data/task8_1.txt" << endl;
        cout << "Желаете ли вы использовать его?" << endl;
        cout << "\t0 - нет\t1 - да" << endl;

        T* arr = nullptr;
        int size = 0;

        if (input<bool>("Неверный ввод, попробуйте ещё раз")) {
            arr = getArrayFromFile<T>(size);
        } else {
            arr = getArrayFromInput<T>(size);
        }

        if (!arr) {
            break;
        }

        cout << "Исходные данные: ";
        printArray(arr, size);
        cout << endl;

        //

        cout << "Введите минимальное значение (A): ";
        T A = input<T>("Некорректное значение, повторите ввод");

        cout << "Введите максимальное значение (B): ";
        T B = input<T>("Некорректное значение, повторите ввод");

        if (A > B) {
            const T temp = A;
            A = B;
            B = temp;

            cout << "A > B, поэтому числа поменялись местами" << endl;
        }

        int count = countBetweenElements(arr, size, A, B);
        if (count != -1) {
            cout << "Количество элементов, лежащих в диапазоне от " << A << " до " << B << ", равно " << count << endl;
        } else {
            cout << "Ошибка массива" << endl;
        }

        //

        int maxIndex = maxElementIndex(arr, size);
        if (maxIndex != -1) {
            cout << "Найденное максимальное значение - " << arr[maxIndex] << ", его индекс - " << maxIndex << endl;

            T sum = sumAfterIndex(arr, size, maxIndex);

            cout << "Сумма элементов, расположенных после максимального элемента: " << sum << endl;

        } else {
            cout << "Не удалось найти максимальный индекс" << endl;
        }

        //

        sortByAbsDesc(arr, size);

        cout << "Отсортированный массив по убыванию модуля элемента: ";
        printArray(arr, size);
        cout << endl;

        //

        delete[] arr;

        cout << "Вы хотите перезапустить задачу?" << endl;
        cout << "\t0 - нет\t1 - да" << endl;

        if (!input<bool>("Некорректное значение, повторите ввод.")) {
            break;
        }
    }
}

void task8_1() {
    // Если нужно, чтобы он работал с целыми числами, то просто указываем тут int.
    _task8_1<float>();
}