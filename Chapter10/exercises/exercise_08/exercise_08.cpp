#include "exercise_08.h"


void f()
{
    fileMerge("one.txt", "two.txt");
}

int main()
{
    try
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR." << endl;
    }
}
