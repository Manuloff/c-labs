//
// Created by nikita on 17.04.2025.
//

#include <stdio.h>

// Проверка на гласную
int isVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'u':
        case 'y':
        case 'o':
            return 1;
        default:
            return 0;
    }
}

// Проверка на пробел
int isSpace(char c) {
    return c == ' ';
}

// Проверка на букву (A-Za-z)
int isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Перевод символа в верхний регистр
char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        const int diff = 'a' - 'A'; // 32
        return (char) (c - diff);
    }

    return c;
}

char processChar(char c, int isStartOfWords) {
    if (isStartOfWords && isVowel(c)) {
        return toUpper(c);
    }

    return c;
}

void processStream(FILE *file) {
    int c;
    int newWord = 1;

    while ((c = fgetc(file)) != EOF) {
        char outChar = processChar((char) c, newWord);
        printf("%c", outChar);

        newWord = isSpace((char) c);
    }
}

void task7_5() {
    printf("Задание 13 варианта:\n");
    printf("Написать программу, которая считывает английский текст из файла и выводит\n"
           "его на экран, заменив каждую первую букву слов, начинающихся с гласной\n"
           "буквы, на прописную.\n\n");

    while (1) {
        FILE *file = fopen("../data/task7_5.txt", "r");

        if (file) {
            printf("Обработанный текст:\n");
            processStream(file);

            printf("\n");


        } else {
            printf("Ошибка открытия файла data/task7_5.txt");
        }

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
