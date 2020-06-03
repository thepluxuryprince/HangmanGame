#ifndef HANGMAN_H
#define HANGMAN_H
void hangman(int n);
int mainMenuPrint();
int victoryCondition(int guessChar, char* word);
int loseCondition(int guessErr, char* word);
int createSword(int sizeWord, char* secretWord);
#endif
