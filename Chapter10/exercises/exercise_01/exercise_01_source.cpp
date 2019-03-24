#include "exercise_01.h"

int sumFile(string filename)
{
    int sum = 0;
    int i;
    ifstream ist{filename};
    while (ist >> i)
    {
        sum += i;
    }
    return sum;
}