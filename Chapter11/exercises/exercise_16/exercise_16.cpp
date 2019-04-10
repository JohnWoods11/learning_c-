#include "exercise_16.h"

void f()
{
    parseNumbers("input.txt");
}


int main()
{
    try
    {
        f();
    }
    catch(...)
    {
        cout << "MAJOR ERROR\n";
        return -1;
    }
    return 0;   
}