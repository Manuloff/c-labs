#include <stdio.h>
#include <malloc.h>

//
// Created by nikita on 17.04.2025.
//

void printArray(int size, float *arr) {
    if (size == 0) {
        printf("[]\n");
        return;
    }

    printf("[%0.2f", arr[0]);

    for (int i = 1; i < size; ++i) {
        printf(", %0.2f", arr[i]);
    }

    printf("]\n");
}

float* getArrayFromInput() {
    int size;

    printf("Введите размерность массива: ");
    scanf("%d", &size);

    if (size < 1) {
        printf("Некорректное значение размера массива (%d), значение установлена на 3", size);

        size = 3;
    }

    //

    printf("Назначение значений элементов:");

    float *arr = malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        printf("%d.", i + 1);
        scanf("%f", &arr[i]);
    }

    return arr;
}

float* loadArray() {
    FILE *file = fopen("../../data/task3_rework.txt", "r");
    if (!file) {
        printf("Не удалось открыть файл task3_rework.txt\n");
        return ;
    }

    int size = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n') {
            break;
        }

        size++;
    }

    printf("Строк считано: %d\n", size);

    notes = malloc(size * sizeof(struct Note));

    rewind(file);
}

void runTask() {
    int useFile;

    printf("Можно использовать заранее заготовленный массив из файла data/task3_rework.txt\n");
    printf("Желаете ли вы использовать его?\n");
    printf("\t0 - нет\t1 - да\n");

    scanf("%d", &useFile);

    float *arr;

    if (useFile == 0) {
        arr = getArrayFromInput();

    } else if (useFile == 1) {
        arr = loadArray();

    } else {
        printf("Недопустимое значение %d\n", useFile);
        runTask();
        return;
    }

    free(arr);

    int taskRestart;

    printf("Для перезапуска лабораторной работы введите 1,\n"
           "\tдля возвращения к выбору другой лабораторной работе - 0\n");

    scanf("%d", &taskRestart);

    if (taskRestart) {
        runTask();
        return;
    }
}

void task3_rework() {
    printf("Общее задание:\n");
    printf("\tИсходные данные для всех вариантов — n вещественных величин. При написании\n"
           "\tпрограмм можно использовать как динамические, так и не-динамические массивы.\n"
           "\tРазмерность последних задавать именованной константой.\n");

    printf("\nЗадание варианта 13:\n");

    printf("1. Найти количество элементов массива, лежащих в диапазоне от А до В.\n");
    printf("2. Найти сумму элементов массива, расположенных после максимального элемента.\n");
    printf("3. Упорядочить элементы массива по убыванию модулей элементов.\n");

    runTask();
}