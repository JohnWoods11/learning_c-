#include "exercise_11.h"

void f()
{
    cout << sumFileNum("text.txt") << endl;
}

int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR";
    }
}