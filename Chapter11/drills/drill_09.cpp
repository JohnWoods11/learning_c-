#include "../stdlibfacilities.h"


void f()
{
    double num = 1234567.89;

    cout << defaultfloat << num << "\n" << fixed << num << "\n" << scientific << num << "\n";
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


// fixed returns the most accurate representation because it does not round the result and shows the value precisely.