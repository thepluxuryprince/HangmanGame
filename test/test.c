#define CTEST_MAIN

#include "hangman.h"
#include <ctest.h>
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
