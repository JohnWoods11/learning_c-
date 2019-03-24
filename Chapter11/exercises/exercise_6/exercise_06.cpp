#include "exercise_06.h"

void f()
{
    removePunctuation("This, and. that; ' \" ' , . \" should?");
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
        return -1;
    }
    return 0;
}