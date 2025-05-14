//
// Created by nikita on 20.03.25.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../tasks.h"

void task3() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Указан некорректный размер массива");
        return;
    }

    float *arr = malloc(n * sizeof(float));

    printf("Введите элементы массива:\n");

    for (int i = 0; i < n; i++) {
        printf("%d. ", i + 1);
        scanf("%f", &arr[i]);
    }

    printf("Введенный массив: [%.2f", arr[0]);

    for (int i = 1; i < n; i++) {
        printf(", %.2f", arr[i]);
    }

    printf("]\n");

    //

    float A, B;

    printf("Введите минимальное значение (A): ");
    scanf("%f", &A);

    printf("Введите максимальное значение (B): ");
    scanf("%f", &B);

    if (A > B) {
        const float temp = A;
        A = B;
        B = temp;

        printf("A > B, поэтому числа поменялись местами\n");
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        float element = arr[i];

        if (A > element || B < element) {
            continue;
        }

        count++;
    }

    printf("Количество элементов, лежащий в диапозоне от %.2f до %.2f, равно %d\n", A, B, count);

    // Нахождение суммы элементов массива, расположенных после максимального элемента

    float maxValue = arr[0];
    int maxIndex = 0;

    // Первая итерация находит индекс максимального числа
    for (int i = 1; i < n; ++i) {
        const float element = arr[i];

        if (maxValue > element) {
            continue;
        }

        maxValue = element;
        maxIndex = i;
    }

    float sum = 0;

    // Вторая итерация суммирует числа после максимального значения
    for (int i = maxIndex + 1; i < n; i++) {
        sum += arr[i];
    }

    printf("Найденное максимальное значение - %.2f, его индекс - %d\n", maxValue, maxIndex);
    printf("Сумма элементов, расположенных после максимального значения, равна %.2f\n", sum);

    // Упорядочивание элементов массива по убыванию модулю массива

    for (int k = 0; k < n - 1; k++) {
        float value = arr[k];
        int index = k;

        for (int i = k + 1; i < n; i++) {
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

    printf("Отсортированный массив по убыванию модулю элемента: [%.2f", arr[0]);
    for (int i = 1; i < n; i++) {
        printf(", %.2f", arr[i]);
    }

    printf("]\n");

    free(arr);
}