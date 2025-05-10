//
// Created by nikita on 03.05.2025.
//

#include <iostream>
#include <fstream>
#include "../tasks.h"

using namespace std;

template <typename T>
void printMatrix(T** matrix, const int rows, const int cols) {
    if (matrix == nullptr || rows < 0 || cols < 0) {
        return;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << matrix[row][col] << ' ';
        }

        cout << endl;
    }
}

template <typename T>
T** getMatrixFromInput(int& rows, int& cols) {
    cout << "Введите количество строк в матрице: ";
    rows = input<int>("Некорректное значение, попробуйте ещё раз");

    if (rows < 1) {
        cout << "Некорректное значение для количества строк (" << rows << "), значение автоматически изменено на 3" << endl;
        rows = 3;
    }

    cout << "Введите количество столбцов в матрице: ";
    cols = input<int>("Некорректное значение, попробуйте ещё раз");

    if (cols < 1) {
        cout << "Некорректное значение для количества столбцов (" << cols << "), значение автоматически изменено на 3" << endl;
        cols = 3;
    }

    T** matrix = new T*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new T[cols];
    }

    cout << "Ввод данных для матрицы:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = input<T>("Некорректное значение, попробуйте ещё раз");
        }
    }

    return matrix;
}

template <typename T>
T** getMatrixFromFile(int& rows, int& cols) {
    ifstream file("../data/task8_2.txt");
    if (!file.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        rows = 0, cols = 0;
        return nullptr;
    }

    char x;

    if (!(file >> rows >> x >> cols) || x != 'x') {
        cout << "Ошибка чтения файла" << endl;
        rows = 0, cols = 0;
        return nullptr;
    }

    T** matrix = new T*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new T[cols];
    }

    bool failed = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(file >> matrix[i][j])) {
                cout << "Ошибка чтения элемента [" << i << "][" << j << ']' << endl;
                failed = true;
                break;
            }
        }
    }

    if (failed) {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }

        delete[] matrix;

        return nullptr;
    }

    return matrix;
}

template <typename T>
void shiftMatrix(T** matrix, const int rows, const int cols, const int mode, int shift) {
    // Что-то вроде "определения движения"
    // если mode==1 -> dr=0, dc=1;
    // если mode==2 -> dr=1, dc=0
    int dr = (mode == 2); // Движение вниз
    int dc = (mode == 1); // Движение вправо

    // Фикс смещения
    shift %= (dr ? rows : cols);
    if (shift < 0) {
        // Если значение шифта меньше нуля, то достаточно прибавить
        // rows/cols в зависимости от выбранного режима.
        // После нахождения остатка от rows/cols мы гарантированно получим
        // значение шифта, которое будет больше или равно нулю.

        shift += (dr ? rows : cols);
    }

    // Создадим временную матрицу, чтобы с ней можно
    // было работать в пределах этой функции.
    T** temp = new T*[rows];

    for (int i = 0; i < rows; i++) {
        temp[i] = new T[cols];
    }

    // Запишем во временную матрицу элементы под их новым индексом
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // При mode == 1 изменяется только nj, а ni остается неизменной,
            // при mode == 2 всё наоборот: ni меняется, nj - неизменна.

            int ni = (i + dr * shift) % rows;
            int nj = (j + dc * shift) % cols;

            temp[ni][nj] = matrix[i][j];
        }
    }

    // Скопируем временную матрицу в исходную
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = temp[i][j];
        }
    }

    // Высвободим память временной матрицы
    for (int i = 0; i < rows; i++) {
        delete[] temp[i];
    }

    delete[] temp;
}

template <typename T>
void _task8_2() {
    cout << "Общее задание:" << endl;
    cout << "\tЗадания этого семинара соответствуют приведенным в Учебнике на с. 139." << endl;
    cout << "\tРекомендуется выполнять каждое задание в двух вариантах: используя локальные" << endl;
    cout << "\tи динамические массивы. Размерности локальных массивов задавать именованными" << endl;
    cout << "\tконстантами, значения элементов массива — в списке инициализации. Ввод" << endl;
    cout << "\tданных в динамический массив выполнять из файла. Более сложные задания на" << endl;
    cout << "\tмассивы приведены в Учебнике на с. 142." << endl;

    cout << "Задание варианта 13:" << endl;
    cout << "\tОсуществить циклический сдвиг элементов прямоугольной матрицы на n элементов" << endl;
    cout << "\tвправо или вниз (в зависимости от введенного режима). n может быть больше" << endl;
    cout << "\tколичества элементов в строке или столбце." << endl;

    while (true) {
        cout << "Можно использовать заранее заготовленную матрицу из файла data/task8_2.txt" << endl;
        cout << "Желаете ли вы использовать его?" << endl;
        cout << "\t0 - нет\t1 - да" << endl;

        T** matrix;
        int cols = 0, rows = 0;

        if (input<bool>("Неверный ввод, попробуйте ещё раз")) {
            matrix = getMatrixFromFile<T>(rows, cols);
        } else {
            matrix = getMatrixFromInput<T>(rows, cols);
        }

        if (!matrix) {
            continue;
        }

        cout << "Исходный данные:" << endl;
        printMatrix(matrix, rows, cols);

        //

        cout << "Выберите в какую сторону будет выполняться смещение:" << endl;
        cout << "\t1 - вправо \t2 - вниз" << endl;

        int mode = input<int>("Неверный ввод, попробуйте ещё раз");

        if (mode != 1 && mode != 2) {
            cout << "Неизвестная сторона смещения (" << mode << ')' << endl;
            continue;
        }

        cout << "На сколько будет выполнен сдвиг: ";
        int shift = input<int>("Неверный ввод, попробуйте ещё раз");

        shiftMatrix(matrix, rows, cols, mode, shift);

        cout << "Матрица со сдвигом:" << endl;
        printMatrix(matrix, rows, cols);

        //

        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }

        delete[] matrix;

        //

        cout << "Вы хотите перезапустить задачу?" << endl;
        cout << "\t0 - нет\t1 - да" << endl;

        if (!input<bool>("Некорректное значение, повторите ввод.")) {
            break;
        }
    }
}

void task8_2() {
    _task8_2<int>();
}