#ifndef HANGMAN_H
#define HANGMAN_H
void hangman(int n);
int mainMenuPrint();
int isWordiuc(char ch);
int victoryCondition(int guessChar, char* word);
int loseCondition(int guessErr, char* word);
void hangmanPrint(int guessErr, char* secretWord, char* enterLetter);
int createSword(int sizeWord, char* secretWord);
#endif
