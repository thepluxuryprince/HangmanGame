#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE* fp;
    int themes;

    themes = mainMenuPrint();
    if (themes == 1) {
        if (!(fp = fopen("SCHOOL.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }

    } else if (themes == 2) {
        if (!(fp = fopen("SPORT.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }

    } else if (themes == 3) {
        if (!(fp = fopen("WorldLead.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }

    } else if (themes == 4) {
        if (!(fp = fopen("AUTO.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }

    } else if (themes == 5) {
        if (!(fp = fopen("COUNTRY.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }

    } else if (themes == 6) {
        if (!(fp = fopen("FOOD.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    } else if (themes == 7) {
        if (!(fp = fopen("LANGUAGE.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }

    } else if (themes == 8) {
        if (!(fp = fopen("PLANETS.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    fclose(fp);
    return 0;
}
