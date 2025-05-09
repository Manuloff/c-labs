//
// Created by nikita on 17.04.2025.
//
#include <stdio.h>
#include "../tasks.h"

void task7() {
    printf("\nЗадание седьмого семинара включает в себя переделку"
           " заданий третьего, четвертого и пятого семинара с помощью функций\n");

    printf("Для продолжения введите номер семинара, который вы хотите запустить.\n");
    printf("\t3. Одномерные массивы\n");
    printf("\t4. Двумерные массивы\n");
    printf("\t5. Строки и файлы\n");

    printf("Либо вы можете вернуться в выбору заданий, написав в ответ - 0\n");

    while (1) {
        int input;

        printf("\nВведите номер переработанной работы:\n");
        scanf("%d", &input);

        switch (input) {
            case 0:
                return;
            case 1:
                task7_1();
                break;
            case 2:
                task7_2();
                break;
            case 3:
                task7_3();
                break;
            default:
                printf("Работы с номером %d не существует", input);
                break;
        }
    }
}