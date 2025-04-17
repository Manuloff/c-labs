//
// Created by nikita on 20.03.25.
//
#include <ctype.h>
#include <stdio.h>

#include "../tasks.h"

void task5() {
    FILE *file = fopen("../data/task5.txt", "r");
    if (!file) {
        printf("Ошибка чтения файла\n");
        return;
    }

    int c;
    int newWord = 1;

    printf("Обработанный текст:\n");

    while ((c = fgetc(file)) != EOF) {
        if (newWord && isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
                c = toupper(c);
            }

            newWord = 0;

        } else {
            newWord = isspace(c);
        }

        printf("%c", c);
    }

    printf("\n");

    fclose(file);
}