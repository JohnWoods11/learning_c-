#include "exercise_15.h"

void f()
{
    outputSci("input.txt");
}

int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR\n";
        return -1;
    }
    return 0;
}