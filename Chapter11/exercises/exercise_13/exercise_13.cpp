#include "exercise_13.h"

void f()
{
    string s = "input.txt";
    reverseFileWords(s);
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