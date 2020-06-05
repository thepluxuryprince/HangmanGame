#define CTEST_MAIN

#include "hangman.h"
#include <ctest.h>
CTEST(victoryCondition, correct_input)
{
    int guessErr = 2;
    int guessChar = 0;
    char word[] = {"test"};
    int result = victoryCondition(guessChar, word, guessErr);
    ASSERT_EQUAL(result, 1);
}

CTEST(victoryCondition, incorrect_input)
{
    int guessErr = 1;
    int guessChar = 6;
    char word[] = {"test"};
    int result = victoryCondition(guessChar, word, guessErr);
    ASSERT_EQUAL(result, -1);
}

CTEST(loseCondition, correct_input)
{
    int guessErr = 6;
    char word[] = {"test"};
    int result = loseCondition(guessErr, word);
    ASSERT_EQUAL(result, 1);
}
CTEST(isWordiuc, up_case_ch)
{
    char ch[1] = {"B"};
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_STR("B", ch);
}
CTEST(isWordiuc, up_case)
{
    char ch[1] = {"B"};
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_EQUAL(result, 1);
}
CTEST(isWordiuc, wrong_input_ch)
{
    char ch[1] = {";"};
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_STR(";", ch);
}
CTEST(isWordiuc, wrong_input)
{
    char ch[1] = {";"};
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_EQUAL(result, -1);
}
CTEST(isWordiuc, low_case)
{
    char ch[1] = {"s"};
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_EQUAL(1, result);
}
CTEST(isWordiuc, low_case_ch)
{
    char ch[1] = {"s"};
    int result = 0;
    result = isWordiuc(ch);
    ASSERT_STR("S", ch);
}
CTEST(loseCondition, incorrect_input)
{
    int guessErr = 0;
    char word[] = {"test"};
    int result = loseCondition(guessErr, word);
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
    int result = check(test_word, &sChar, eLetter, &guessChar, sWord);
    ASSERT_EQUAL(result, 0);
}

CTEST(check, incorrect_input)
{
    char test_word[] = {"auto"}, eLetter[] = {"bcd"}, sWord[] = {"____"};
    char sChar = 'z';
    int guessChar = 4;
    int result = check(test_word, &sChar, eLetter, &guessChar, sWord);
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
    int a = 4;
    char ch = 'W';
    char enterLetter[20] = {"ASDC"};
    int result = enterlet(enterLetter, &a, &ch);
    ASSERT_EQUAL(result, 1);
}
CTEST(enterlet, correct_input_ch)
{
    int a = 4;
    char ch = 'W';
    char enterLetter[20] = {"ASDC"};
    int result = enterlet(enterLetter, &a, &ch);
    ASSERT_STR("ASDCW", enterLetter);
}
CTEST(enterlet, incorrect_input)
{
    int a = 4;
    char ch = 'A';
    char enterLetter[20] = {"ASDC"};
    int result = enterlet(enterLetter, &a, &ch);
    ASSERT_EQUAL(result, -1);
}
CTEST(enterlet, incorrect_input_ch)
{
    int a = 4;
    char ch = 'A';
    char enterLetter[20] = {"ASDC"};
    int result = enterlet(enterLetter, &a, &ch);
    ASSERT_STR("ASDC", enterLetter);
}
void test_hangman()
{
    for (int i = 0; i <= 6; i++) {
        hangman(i);
    }
}
CTEST(rndStr, in_area)
{
    int result1 = randomStr();
    ASSERT_INTERVAL(1, 10, result1);
}
int main(int argc, const char** argv)
{
    test_hangman();
    test_hangmanPrint();
    return ctest_main(argc, argv);
}
