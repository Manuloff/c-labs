//
// Created by nikita on 20.03.25.
//

#include <stdio.h>
#include <stdlib.h>

#include "../tasks.h"

void task4(void) {
    int rows, cols;

    printf("Введите размерность матрицы (IxJ): ");
    scanf("%d %d", &rows, &cols);

    // Проверка размеров матрицы
    if (rows < 1 || cols < 1) {
        printf("Размерность матрицы указана не корректно (%dx%d)\n", rows, cols);
        return;
    }

    // Выделение памяти
    int **matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(rows * sizeof(int));
    }

    // Ввод элементов
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Введенная матрица:\n");

    // Вывод матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    int mode;

    printf("Выберите в какую сторону будет выполняться смещение (1 - вправо, 2 - вниз): ");
    scanf("%d", &mode);

    int n;
    printf("На сколько будет выполнен сдвиг: ");
    scanf("%d", &n);

    if (mode == 1) {
        for (int i = 0; i < rows; i++) {
            int *temp = malloc(cols * sizeof(int));

            for (int j = 0; j < cols; j++) {
                const int newPos = (j + n) % cols;

                temp[newPos] = matrix[i][j];
            }

            for (int j = 0; j < cols; j++) {
                matrix[i][j] = temp[j];
            }

            free(temp);
        }

    } else if (mode == 2) {
        for (int j = 0; j < cols; j++) {
            int *temp = malloc(rows * sizeof(int));

            for (int i = 0; i < rows; i++) {
                const int newPos = (i + n) % rows;

                temp[newPos] = matrix[i][j];
            }

            for (int i = 0; i < rows; i++) {
                matrix[i][j] = temp[i];
            }

            free(temp);
        }

    } else {
        printf("Указан некорректный режим (n = %d)\n", n);
        return;
    }

    printf("Получившаяся матрица:\n");

    // Вывод матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    // Высвобождение памяти
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);
}
