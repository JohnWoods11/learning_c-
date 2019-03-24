#include "exercise_09.h"

void f()
{
    mergeSortedFiles("file_one", "file_two");
}


int main()
{
    try
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR" << endl;
        return -1;
    }
    return 0;
}