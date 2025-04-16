//
// Created by nikita on 20.03.25.
//
#include <math.h>
#include <stdio.h>

#include "../tasks.h"

void task2() {
    float start, end, dx, e;

    printf("Введите начальное значение: ");
    scanf("%f", &start);

    printf("Введите конечное значение: ");
    scanf("%f", &end);

    printf("Введите шаг: ");
    scanf("%f", &dx);

    printf("Введите точность: ");
    scanf("%f", &e);

    printf("---------------------------\n");
    printf("|    x   |  f(x)  |   n   |\n");

    for (float x = start; x <= end; x += dx) {
        double term = x / 2;
        double sum = 0;

        int n = 1;

        while (fabs(term) > e) {
            sum += term;
            n++;
            term = pow(-1, n - 1) * // Отвечает за -+
                (pow(x, n) / (pow(2, n) * n));
        }

        printf("| %6.4f | %6.4f | %5d |\n", x, sum, n - 1);
    }

    printf("---------------------------\n");
}