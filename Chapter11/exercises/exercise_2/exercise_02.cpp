#include "exercise_02.h"

void f()
{
    linesContaining("input.txt", "compute");
}

int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "FATAL ERROR" << "\n";
        return -1;
    }
    return 0;
}