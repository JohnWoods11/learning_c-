#include "exercise_03.h"

void f()
{
    disemvowel("input.txt");
}

int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}
