#include "../stdlibfacilities.h"

void f()
{
    int birth_year = 1989;
    int age = 29;

    cout << "dec\t" << birth_year << "\nhex\t" << hex << birth_year << "\noct\t" << oct << birth_year << "\n"<< dec << age << "\n" ;
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