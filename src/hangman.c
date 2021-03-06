#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int check(char* word, char* sChar, char* eLetter, int* guessChar, char* sWord)
{
    int flag = 1;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == *sChar) {
            flag = 0;
            if (!(strchr(eLetter, *sChar))) {
                (*guessChar)--;
            }
            sWord[i] = *sChar;
            if (strchr(eLetter, *sChar)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        return 0;
    }
    return 1;
}

void hangmanPrint(int guessErr, char* secretWord, char* enterLetter)
{
    hangman(guessErr);
    printf("%s\n", secretWord);
    printf("Введенные буквы: ");
    printf("%s", enterLetter);
    printf("\nВведите букву:\n");
}

int loseCondition(int guessErr, char* word)
{
    if (guessErr == 6) {
        hangman(6);
        printf("%s", word);
        printf("\nВы проиграли(\n");
        return 1;
    }
    return -1;
}

int victoryCondition(int guessChar, char* word, int guessErr)
{
    if (guessChar == 0) {
        hangman(guessErr);
        printf("%s", word);
        printf("\nВы победили!\n");
        return 1;
    }
    return -1;
}

int isWordiuc(char* ch)
{
    if (*ch >= 'a' && *ch <= 'z') {
        *ch = *ch - ('a' - 'A');
        return 1;
    }
    if (*ch >= 'A' && *ch <= 'Z') {
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

int isTheme(int themes)
{
    if (themes >= 1 && themes <= 8) {
        return 1;
    }
    return -1;
}
int randomStr()
{
    srand(time(NULL));
    int rndStr = (rand() % 10) + 1;
    if (rndStr == 0) {
        rndStr++;
    }
    return rndStr;
}
int enterlet(char* enterLetter, int* iter, char* ch)
{
    int flg = 1;
    for (int k = 0; k < *iter; k++) {
        if (enterLetter[k] == *ch) {
            flg = -1;
            (*iter)--;
            return flg;
        }
    }
    enterLetter[*iter] = *ch;
    enterLetter[*iter + 1] = '\0';
    return flg;
}
