#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hangman(int n)
{
    switch (n) {
    case 6:
        printf(" \n\n   HANGMAN \n\n +=========+\n  | \t||\n  O \t||\n "
               "|||\t||\n  | \t||\n | |\t||\n | |\t||\n +=========+\n");
        break;
    case 5:
        printf(" \n\n   HANGMAN \n\n +=========+\n    \t||\n    \t||\n "
               "|||\t||\n  | \t||\n | |\t||\n | |\t||\n +=========+\n");
        break;
    case 4:
        printf(" \n\n   HANGMAN \n\n +=========+\n    \t||\n    \t||\n    "
               "\t||\n  | \t||\n | |\t||\n | |\t||\n +=========+\n");
        break;
    case 3:
        printf(" \n\n   HANGMAN \n\n +=========+\n    \t||\n    \t||\n    "
               "\t||\n    \t||\n | |\t||\n | |\t||\n +=========+\n");
        break;
    case 2:
        printf(" \n\n   HANGMAN \n\n +=========+\n    \t||\n    \t||\n    "
               "\t||\n    \t||\n    \t||\n | |\t||\n +=========+\n");
        break;
    case 1:
        printf(" \n\n   HANGMAN \n\n +=========+\n    \t||\n    \t||\n    "
               "\t||\n    \t||\n    \t||\n    \t||\n +=========+ \n");
        break;
    case 0:
        printf(" \n\n   HANGMAN \n\n +=========+\n    \t||\n    \t||\n    "
               "\t||\n    \t||\n    \t||\n    \t||\n +=========+\n");
        break;
    }
}
int createSword(int sizeWord, char* secretWord)
{
    if (sizeWord >= 3 && sizeWord <= 10) {
        secretWord = (char*)calloc(sizeWord, sizeof(char));
        if (secretWord == NULL) {
            return -1;
        }
        memset(secretWord, '_', sizeWord);
        return 1;
    }
    return -1;
}
int mainMenuPrint()
{
    int themes;
    printf("Добро пожаловать в игру HANGMAN!\n Выберите тему для игры!\n\n");
    printf(" 1.Школа\n 2.Спорт\n 3.Мировые Лидеры\n 4.Марки Машин\n 5.Страны\n "
           "6.Еда\n 7.Языки\n 8.Планеты\n");
    printf("Введите число выбранной темы:");
    scanf("%d", &themes);
    return themes;
}
