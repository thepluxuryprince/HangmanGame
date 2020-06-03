#include "hangman.h"
#include <stdio.h>

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
