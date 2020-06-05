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
    char word[] = {"test"};
    int result = victoryCondition(guessChar, word);
    ASSERT_EQUAL(result, 1);
}

CTEST(victoryCondition, incorrect_input)
{
    int guessChar = 6;
    char word[] = {"test"};
    int result = victoryCondition(guessChar, word);
    ASSERT_EQUAL(result, -1);
}

CTEST(loseCondition, correct_input)
{
    int guessErr = 6;
    char word[] = {"test"};
    int result = loseCondition(guessErr, word);
    ASSERT_EQUAL(result, 1);
}
CTEST(isWordiuc, up_case)
{
    char ch = 'A';
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_EQUAL(result, 1);
}
CTEST(isWordiuc, wrong_input)
{
    char ch = '2';
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_EQUAL(result, -1);
}
CTEST(isWordiuc, low_case)
{
    char ch = 'a';
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_EQUAL(result, 1);
}
CTEST(loseCondition, incorrect_input)
{
    int guessErr = 0;
    char word[] = {"test"};
    int result = loseCondition(guessErr, word);
    ASSERT_EQUAL(result, -1);
}
CTEST(createSword, incorrect_input)
{
    char* secretWord;
    int result = createSword(-1, secretWord);
    ASSERT_EQUAL(result, -1);
}
CTEST(isTheme, correct_input)
{
    int theme = 2;
    int result = isTheme(theme);
    ASSERT_EQUAL(result, 1);
}
CTEST(isTheme, incorrect_input)
{
    int theme = 99;
    int result = isTheme(theme);
    ASSERT_EQUAL(result, -1);
}

CTEST(check, correct_input)
{
    char test_word[] = {"auto"}, eLetter[] = {"bcd"}, sWord[] = {"____"};
    char sChar = 'a';
    int guessChar = 4;
    int result = check(test_word, sChar, eLetter, guessChar, sWord);
    ASSERT_EQUAL(result, 0);
}

CTEST(check, incorrect_input)
{
    char test_word[] = {"auto"}, eLetter[] = {"bcd"}, sWord[] = {"____"};
    char sChar = 'z';
    int guessChar = 4;
    int result = check(test_word, sChar, eLetter, guessChar, sWord);
    ASSERT_EQUAL(result, 1);
}

void test_hangmanPrint()
{
    int guessErr = 5;
    char secretWord[] = {"_____"};
    char enterLetter[] = {"abcde"};
    printf("\n<<test_hangmanPrint>>\n");
    hangmanPrint(guessErr, secretWord, enterLetter);
    printf("\n");
}
CTEST(enterlet, correct_input)
{
    char enterLetter[20] = {"ASDC"};
    int result = enterlet(enterLetter, 4, 'W');
    printf("%s", enterLetter);
    ASSERT_EQUAL(result, 1);
}
CTEST(enterlet, incorrect_input)
{
    char enterLetter[20] = {"ASDC"};
    int result = enterlet(enterLetter, 4, 'A');
    printf("%s", enterLetter);
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
    test_hangmanPrint();
    return ctest_main(argc, argv);
}
