#include "exercise_01.h"

void f()
{
    cout << sumFile("nums.txt") << endl;
}


int main()
{
    try
    {
        f();
    }
    catch (...)
    {
        cout << "Major error." << endl;
    }
}