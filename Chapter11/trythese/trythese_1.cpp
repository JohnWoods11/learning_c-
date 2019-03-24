#include "../stdlibfacilities.h"

void f()
{ 
    cout << "Day\tMonth\tYear" << endl 
    << 21 << "\t" << 9 << "\t" << 1989 << endl 
    << hex << 21 << "\t" << 9 << "\t" << 1989 << endl 
    << oct << 21 << "\t" << 9 << "\t" << 1989 << endl;
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