#include "exercise_07.h"

void f()
{
    removePunctuation(" - don't use the as-if rule. \" - don't use the as-if rule. \" ");
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