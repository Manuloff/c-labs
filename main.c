#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main(void) {
    setlocale(LC_ALL, "C.UTF-8");

    // Только для Windows — установить кодовую страницу UTF-8
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    printf("Подготовлено студентом Уваровым Никитой из группы 4ИТБ-2\n");
    printf("Все лабораторные работы выполнялись под 13 вариантом\n\n");

    printf("Список доступных лабораторных\n");
    printf("1. Линейные программы\n");
    printf("2. Ветвления и циклы\n");
    printf("3. Одномерные массивы и указатели\n");
    printf("4. Двумерные массивы\n");
    printf("5. Строки и файлы\n");
    printf("6. Структура\n");
    printf("7. Функции\n");
    printf("8. Перегрузка и шаблоны функций\n");

    while (1) {
        printf("\nВведите номер лабораторной работы, которой вы хотите запустить:\n");

        int n;
        scanf("%d", &n);

        switch (n) {
            case 0:
                exit(1);
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                task7();
                break;
            case 8:
                task8();
                break;
            default:
                printf("Лабораторной с номером %d не существует", n);
        }
    }
}
