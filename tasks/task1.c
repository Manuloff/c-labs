//
// Created by nikita on 20.03.25.
//

#include <math.h>
#include <stdio.h>

#include "../tasks.h"

void task1() {
    float alpha, beta;

    printf("Введите альфу: ");
    scanf("%f", &alpha);

    printf("Введите бету: ");
    scanf("%f", &beta);

    const float z1 = (sinf(alpha) + cosf(2 * beta - alpha))
               / (cosf(alpha) - sinf(2 * beta - alpha));

    const float z2 = (1 + sinf(2 * beta)) / cosf(2 * beta);

    printf("z1 = %f\n", z1);
    printf("z2 = %f\n", z2);
}