//
// Created by nikita on 17.04.2025.
//
#include <stdio.h>
#include <malloc.h>
#include <math.h>

void printArray(int size, float *arr) {
    if (size == 0 || arr == NULL) {
        printf("[]\n");
        return;
    }

    printf("[%0.2f", arr[0]);

    for (int i = 1; i < size; ++i) {
        printf(", %0.2f", arr[i]);
    }

    printf("]\n");
}

// Возвращает количество элементов в массиве, находящихся между A и B (включительно).
int countBetweenElements(int size, const float* arr, float A, float B) {
    if (arr == NULL) {
        return -1;
    }

    // Переменная-счётчик.
    int count = 0;

    for (int i = 0; i < size; i++) {
        float element = arr[i];

        // Если элемент меньше A или больше B, то
        if (element < A || element > B) {
            continue;
        }

        count++;
    }

    return count;
}

// Возвращает индекс максимального элемента в массиве
int maxElementIndex(int size, const float* arr) {
    if (size <= 0 || arr == NULL) {
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

// Возвращает сумму элементов, находящихся после элемента с индексом i.
float sumAfterIndex(int size, const float* arr, int index) {
    if (arr == NULL || index < -1 || index >= size) {
        return 0.0f;
    }

    float sum = 0;

    for (int i = index + 1; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

// Сортирует массив по убыванию модуля элемента
void sortByAbsDesc(int size, float* arr) {
    if (arr == NULL || size == 0) {
        return;
    }

    // Сортировка простого выбора
    for (int k = 0; k < size - 1; k++) {
        float value = arr[k];
        int index = k;

        for (int i = k + 1; i < size; i++) {
            const float element = arr[i];

            if (fabsf(value) > fabsf(element)) {
                continue;
            }

            value = element;
            index = i;
        }

        arr[index] = arr[k];
        arr[k] = value;
    }
}

void task7_3() {
    printf("Общее задание:\n");
    printf("\tИсходные данные для всех вариантов — n вещественных величин. При написании\n"
           "\tпрограмм можно использовать как динамические, так и не-динамические массивы.\n"
           "\tРазмерность последних задавать именованной константой.\n");

    printf("\nЗадание варианта 13:\n");

    printf("\t1. Найти количество элементов массива, лежащих в диапазоне от А до В.\n");
    printf("\t2. Найти сумму элементов массива, расположенных после максимального элемента.\n");
    printf("\t3. Упорядочить элементы массива по убыванию модулей элементов.\n\n");

    while (1) {
        int useFile;

        printf("Можно использовать заранее заготовленный массив из файла data/task7_3.txt\n");
        printf("Желаете ли вы использовать его?\n");
        printf("\t0 - нет\t1 - да\n");

        scanf("%d", &useFile);

        int size;
        float* arr;

        if (useFile == 0) {
            printf("Введите размерность массива: ");
            scanf("%d", &size);

            if (size < 1) {
                printf("Некорректное значение размера массива (%d), значение установлена на 3", size);

                size = 3;
            }

            //

            printf("Назначение значений элементов:");

            arr = malloc(size * sizeof(float));

            for (int i = 0; i < size; i++) {
                printf("%d.", i + 1);
                scanf("%f", &arr[i]);
            }

        } else if (useFile == 1) {
            FILE *file = fopen("../data/task7_3.txt", "r");
            if (!file) {
                printf("Не удалось открыть файл task7_3.txt\n");
                continue;
            }

            size = 0;

            char line[256];

            while (fgets(line, sizeof(line), file)) {
                if (line[0] == '\n') {
                    break;
                }

                size++;
            }

            printf("Строк считано: %d\n", size);

            rewind(file);

            arr = malloc(size * sizeof(float));

            for (int i = 0; i < size; i++) {
                if (fscanf(file, "%f", &arr[i]) != 1) {
                    printf("Ошибка чтения строки %d\n", i + 1);
                }
            }

            fclose(file);

        } else {
            printf("Недопустимое значение %d\n", useFile);
            continue;
        }

        printf("Исходные данные: ");
        printArray(size, arr);

        // Найти количество элементов массива, лежащих в диапазоне от А до В

        float A, B;

        printf("Введите минимальное значение (A): ");
        scanf("%f", &A);

        printf("Введите максимальное значение (B): ");
        scanf("%f", &B);

        // Для выполнения кода требуется, чтобы A < B.
        // Если A > B, то их нужно поменять местами.
        if (A > B) {
            const float temp = A;
            A = B;
            B = temp;

            printf("A > B, поэтому числа поменялись местами\n");
        }

        int count = countBetweenElements(size, arr, A, B);

        if (count != -1) {
            printf("Количество элементов, лежащий в диапазоне от %.2f до %.2f, равно %d\n", A, B, count);
        } else {
            printf("Ошибка массива\n");
        }

        // Найти сумму элементов массива, расположенных после максимального элемента.

        int maxIndex = maxElementIndex(size, arr);
        if (maxIndex != -1) {
            printf("Найденное максимальное значение - %.2f, его индекс - %d\n", arr[maxIndex], maxIndex);

            float sum = sumAfterIndex(size, arr, maxIndex);

            printf("Сумма элементов, расположенных после максимального элемента: %.2f\n", sum);

        } else {
            printf("Не удалось найти максимальный индекс\n");
        }

        // Упорядочить элементы массива по убыванию модуля элемента.

        sortByAbsDesc(size, arr);

        printf("Отсортированный массив по убыванию модуля элемента: ");
        printArray(size, arr);

        //

        // Высвобождение памяти
        free(arr);

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