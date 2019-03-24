#include "exercise_14.h"

void f()
{
    string s = "input.txt";
    countCharClassifications(s);
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