#include "exercise_12.h"

void f()
{
    string s = "input.txt";
    reverseFileText(s);
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