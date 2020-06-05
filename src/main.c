#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    FILE* fp;
    char word[10], *secretWord, *enterLetter, scanChar = 0;
    int themes, rndStr, sizeWord, guessChar, guessErr = 0;
    int iter = 0, flag = 0;

    system("clear");
    themes = mainMenuPrint();
    if (isTheme(themes) == -1) {
        printf("Ошибка! Недопустимое знчение номера темы.\n");
        _Exit(EXIT_SUCCESS);
    }
    if (themes == 1) {
        if (!(fp = fopen("SCHOOL.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    if (themes == 2) {
        if (!(fp = fopen("SPORT.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    if (themes == 3) {
        if (!(fp = fopen("WorldLead.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    if (themes == 4) {
        if (!(fp = fopen("AUTO.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    if (themes == 5) {
        if (!(fp = fopen("COUNTRY.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    if (themes == 6) {
        if (!(fp = fopen("FOOD.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    if (themes == 7) {
        if (!(fp = fopen("LANGUAGE.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    if (themes == 8) {
        if (!(fp = fopen("PLANETS.txt", "rt"))) {
            printf("Ошибка открытия файла!\n");
            return 0;
        }
    }
    rndStr = randomStr();
    fseek(fp, 0, SEEK_SET);

    for (int i = 0; i < rndStr; i++) {
        fscanf(fp, "%s", word);
    }
    fclose(fp);

    sizeWord = strlen(word);

    secretWord = (char*)calloc(sizeWord, sizeof(char));
    memset(secretWord, '_', sizeWord);
    enterLetter = (char*)calloc(sizeWord + 6, sizeof(char));
    guessChar = sizeWord;

    while (guessChar >= 0) {
        system("clear");
        if (flag == 1) {
            guessErr++;
        }

        if (victoryCondition(guessChar, word, guessErr) == 1) {
            _Exit(EXIT_SUCCESS);
        }
        if (loseCondition(guessErr, word) == 1) {
            _Exit(EXIT_SUCCESS);
        }
        hangmanPrint(guessErr, secretWord, enterLetter);
        scanf(" %c", &scanChar);
        if (isWordiuc(&scanChar) == -1) {
            printf("Ошибка! Недопустимый символ.\n");
            return 0;
        }
        system("clear");

        flag = check(word, &scanChar, enterLetter, &guessChar, secretWord);

        enterlet(enterLetter, &iter, &scanChar);
        iter++;
        system("clear");
    }

    return 0;
}
