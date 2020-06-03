#define CTEST_MAIN

#include "hangman.h"
#include <ctest.h>
CTEST(createSword, correct_input)
{
    char* secretWord;
    int result = createSword(10, secretWord);
    ASSERT_EQUAL(result, 1);
}
CTEST(victoryCondition, correct_input)
{
    int guessChar = 0;
    char word[] = { "test" };
    int result = victoryCondition(guessChar, word);
    ASSERT_EQUAL(result, 1);
}

CTEST(victoryCondition, incorrect_input)
{
    int guessChar = 6;
    char word[] = { "test" };
    int result = victoryCondition(guessChar, word);
    ASSERT_EQUAL(result, -1);
}

CTEST(loseCondition, correct_input)
{
    int guessErr = 6;
    char word[] = { "test" };
    int result = loseCondition(guessErr, word);
    ASSERT_EQUAL(result, 1);
}

CTEST(loseCondition, incorrect_input)
{
    int guessErr = 0;
    char word[] = { "test" };
    int result = loseCondition(guessErr, word);
    ASSERT_EQUAL(result, -1);
}

CTEST(createSword, incorrect_input)
{
    char* secretWord;
    int result = createSword(-1, secretWord);
    ASSERT_EQUAL(result, -1);
}

void test_hangman()
{
    for (int i = 0; i <= 6; i++) {
        hangman(i);
    }
}
int main(int argc, const char** argv)
{
    test_hangman();
    return ctest_main(argc, argv);
}
