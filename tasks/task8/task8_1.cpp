//
// Created by nikita on 03.05.2025.
//

#include <iostream>
#include <fstream>
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

void task8_1() {
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

        // Нужен массив из целых чисел? Меняем float* на int*
        float* arr = nullptr;
        int size = 0;

        if (input<bool>("Неверный ввод, попробуйте ещё раз")) {
            arr = getArrayFromFile<float>(size);
        } else {
            arr = getArrayFromInput<float>(size);
        }

        if (!arr) {
            break;
        }

        cout << "Исходные данные";
        printArray(arr, size);
        cout << endl;



        delete[] arr;

        cout << "Вы хотите перезапустить задачу?" << endl;
        cout << "\t0 - нет\t1 - да" << endl;

        if (!input<bool>("Некорректное значение, повторите ввод.")) {
            break;
        }
    }
}