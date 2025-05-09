//
// Created by nikita on 17.04.2025.
//
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int rows, int cols, int **matrix) {
    if (matrix == NULL) {
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int** loadMatrixFromFile(int* rows, int* cols) {
    FILE* file = fopen("../data/task7_2.txt", "r");

    /*
     * 3x3
     * 1 2 3
     * 4 5 6
     * 7 8 9
     */

    if (!file) {
        printf("Не удалось открыть файл task7_2.txt\n");
        fclose(file);
        return NULL;
    }

    if (fscanf(file, "%dx%d", rows, cols) != 2) {
        printf("Ошибка чтения размеров матрицы\n");
        fclose(file);
        return NULL;
    }

    // Выделение памяти

    int** matrix = malloc(*rows * sizeof(int*));

    for (int i = 0; i < *rows; ++i) {
        matrix[i] = malloc(*cols * sizeof(int));
    }

    // Переменная, обозначающая ошибку во время чтения файла
    // типа bool - ага, поверили?
    int failed = 0;


    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *cols; ++j) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                printf("Ошибка чтения элемента [%d][%d]\n", i, j);
                failed = 1;
                break;
            }
        }

        if (failed) {
            break;
        }
    }

    //

    // Закрытие потока файла
    fclose(file);

    // В случае ошибки нужно освободить память, выделенную для матрицы
    if (failed) {
        for (int i = 0; i < *rows; ++i) {
            free(matrix[i]);
        }

        free(matrix);

        return NULL;
    }

    return matrix;
}

int** getMatrixFromInput(int* rows, int* cols) {
    // Ввод размеров матрицы

    printf("Введите размеры матрицы (IxJ): ");
    scanf("%dx%d", rows, cols);

    // Валидация и исправление некорректных размеров
    if (*rows < 1 || *cols < 1) {
        printf("Указаны некорректные размеры матрицы - %dx%d\n", *rows, *cols);
        printf("Размеры установлены на 3x3\n");

        *rows = 3;
        *cols = 3;
    }

    // Выделение памяти под матрицу заданных размеров

    int **matrix = malloc(*rows * sizeof(int*));

    for (int i = 0; i < *rows; ++i) {
        matrix[i] = malloc(*cols * sizeof(int));
    }

    // Записываем элементы матрицы

    printf("Ввод данных для матрицы:\n");

    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *cols; ++j) {
            printf("[%d][%d]", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}

void shiftMatrix(int rows, int cols, int **matrix, int mode, int shift) {
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
    int** temp = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; ++i) {
        temp[i] = malloc(cols * sizeof(int));
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
    for (int i = 0; i < rows; ++i) {
        free(temp[i]);
    }

    free(temp);
}

void task7_2() {
    printf("Общее задание:\n");
    printf("\tЗадания этого семинара соответствуют приведенным в Учебнике на с. 139. \n"
           "\tРекомендуется выполнять каждое задание в двух вариантах: используя локальные\n"
           "\tи динамические массивы. Размерности локальных массивов задавать именованными\n"
           "\tконстантами, значения элементов массива — в списке инициализации. Ввод\n"
           "\tданных в динамический массив выполнять из файла. Более сложные задания на\n"
           "\tмассивы приведены в Учебнике на с. 142.\n");

    printf("Задание варианта 13:\n");
    printf("Осуществить циклический сдвиг элементов прямоугольной матрицы на n элементов\n"
           "вправо или вниз (в зависимости от введенного режима). n может быть больше\n"
           "количества элементов в строке или столбце.\n");

    while (1) {
        // Создание матрицы

        int useFile;

        printf("\nМожно использовать заранее заготовленный массив из файла data/task7_2.txt\n");
        printf("Желаете ли вы использовать его?\n");
        printf("\t0 - нет\t1 - да\n");

        scanf("%d", &useFile);

        int** matrix;
        int rows, cols;

        if (useFile == 0) {
            matrix = getMatrixFromInput(&rows, &cols);

        } else if (useFile == 1) {
            matrix = loadMatrixFromFile(&rows, &cols);

        } else {
            printf("Некорректное значение: %d\n", useFile);
            continue;
        }

        if (matrix == NULL) {
            continue;
        }

        // Вывод исходные данных

        printf("Исходные данные:\n");
        printMatrix(rows, cols, matrix);

        //

        int mode;

        printf("Выберите в какую сторону будет выполняться смещение (1 - вправо, 2 - вниз): ");
        scanf("%d", &mode);

        if (mode != 1 && mode != 2) {
            printf("Неизвестная сторона смещения (%d)\n", mode);
            continue;
        }

        int shift;
        printf("На сколько будет выполнен сдвиг: ");
        scanf("%d", &shift);

        shiftMatrix(rows, cols, matrix, mode, shift);

        printf("Матрица со сдвигом:\n");
        printMatrix(rows, cols, matrix);

        //

        // Высвобождение матрицы

        for (int i = 0; i < rows; ++i) {
            free(matrix[i]);
        }

        free(matrix);

        //

        // Перезапуск задания
        int taskRestart;

        printf("\nДля перезапуска введите 1,"
               " для возвращения к выбору - 0\n");

        scanf("%d", &taskRestart);

        if (!taskRestart) {
            break;
        }
    }
}
