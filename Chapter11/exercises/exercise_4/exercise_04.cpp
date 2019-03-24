#include "exercise_04.h"


void f()
{
    multiInput();
}


int main()
{
    try 
    {
        f();
    }
    catch (const exception &err)
    {
        cout << "ERROR: " << err.what() << "\n";
        return -1;
    }
    return 0;
}