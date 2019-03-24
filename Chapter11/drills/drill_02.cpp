#include "../stdlibfacilities.h"

void f()
{
    int birth_year = 1989;

    cout << birth_year << "\n" << hex << birth_year << "\n" << oct << birth_year << "\n";
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