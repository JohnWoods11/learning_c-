#include "../stdlibfacilities.h"

void f()
{
    int birth_year = 1989;
}


int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}