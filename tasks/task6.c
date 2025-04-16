//
// Created by nikita on 20.03.25.
//
#include <stdio.h>
#include <stdlib.h>

#include "../tasks.h"

struct Note {
    char firstName[50];
    char lastName[50];
    char phone[50];
    int birthday[3]; // dd.mm.yyyy
};

void printNote(int i, struct Note note) {
    printf("%02d. %20s%20s|%-12s|%02d.%02d.%04d\n",
           i,
           note.firstName,
           note.lastName,
           note.phone,
           note.birthday[0],
           note.birthday[1],
           note.birthday[2]
    );
}

void task6() {
    int useFile;

    printf("Вы хотите загрузить файл с заготовленными примерами? (task6.txt)\n");
    printf("0 - нет      1 - да\n");

    scanf("%d", &useFile);

    int size;
    struct Note *notes;

    // Файл не используется
    if (useFile == 0) {
        printf("Введите количество записей, которое вы хотите создать: ");
        scanf("%d", &size);

        if (size < 1) {
            printf("Некорректное значение для n (n = %d)\n", size);
            size = 1;

            printf("Значение установлено на 1\n");
        }

        notes = malloc(size * sizeof(struct Note));

        for (int i = 0; i < size; ++i) {
            printf("Ввод данных для записи #%d\n", i + 1);

            printf("Имя: ");
            scanf("%s", notes[i].firstName);

            printf("Фамилия: ");
            scanf("%s", notes[i].lastName);

            printf("Номер телефона: ");
            scanf("%s", notes[i].phone);

            printf("Дата рождения (дд.мм.гггг): ");
            scanf("%d.%d.%d",
                  &notes[i].birthday[0],
                  &notes[i].birthday[1],
                  &notes[i].birthday[2]
            );
        }

    } else if (useFile == 1) {
        FILE *file = fopen("../tasks6.txt", "r");
        if (!file) {
            printf("Не удалось открыть файл tasks6.txt\n");
            return;
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

        notes = malloc(size * sizeof(struct Note));

        rewind(file);

        for (int i = 0; i < size; i++) {
            if (fscanf(file, "%s %s %s %d.%d.%d",
                       notes[i].firstName,
                       notes[i].lastName,
                       notes[i].phone,
                       &notes[i].birthday[0],
                       &notes[i].birthday[1],
                       &notes[i].birthday[2]) != 6) {
                printf("Ошибка чтения строки %d\n", i + 1);
            }
        }

        fclose(file);

        printf("Считанные данные:\n");

        for (int i = 0; i < size; ++i) {
            printNote(i + 1, notes[i]);
        }

    } else {
        return;
    }

    int targetMonth;

    printf("\nВведите месяц: ");
    scanf("%d", &targetMonth);

    printf("Записи, у которых месяц в дате рождения равен %d:\n", targetMonth);

    int count = 0;

    for (int i = 0; i < size; ++i) {
        const struct Note note = notes[i];

        if (note.birthday[1] == targetMonth) {
            count++;

            printNote(count, note);
        }
    }

    if (count == 0) {
        printf("Нет записей, у которых месяц в дате рождения равен %d\n", targetMonth);
    }

    free(notes);
}