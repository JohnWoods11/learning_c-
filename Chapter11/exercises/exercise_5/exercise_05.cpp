#include "exercise_05.h"

void f()
{
    classifyChars("This string.15 \t");
}


int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR.\n";
        return -1;
    }
    return 0;
}