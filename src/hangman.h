#ifndef HANGMAN_H
#define HANGMAN_H
#include <stdio.h>
void hangman(int n);
int randomStr();
int mainMenuPrint();
int isTheme(int themes);
int isWordiuc(char ch);
int enterlet(char* enterLetter, int iter, char ch);
int victoryCondition(int guessChar, char* word);
int loseCondition(int guessErr, char* word);
void hangmanPrint(int guessErr, char* sWord, char* enterLetter);
int createSword(int sizeWord, char* secretWord);
int check(char* word, char* sChar, char* eLetter, int* guessChar, char* sWord);
#endif
