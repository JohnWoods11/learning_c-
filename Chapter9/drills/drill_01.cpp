#include "../stdlibfacilities.h"

struct date
{
    int y;
    int m;
    int d;
};

void init_day (date& dd, int y, int m, int d)
{   
    if ((y < 2100 and y > 1900) and (m > 0 and m < 13) and (d > 0 and d < 31))
    {
        dd.y = y;
        dd.m = m;
        dd.d = d;
    }
    else 
    throw invalid_argument("Bad date");
}

void add_day (date& dd, int n)
{
    if (dd.d == 31)
    {
        if (dd.m == 12)
        {
            dd.d = 1;
            dd.m = 1;
            dd.y += 1;
        }
        else
        {    
        dd.d = 1;
        dd.m += 1;
        }
    }
    else
    {
        dd.d += 1;
    }
}

void f()
{
    date today;
    init_day(today, 2002, 4, 30);
    add_day(today, 2);
}

int main()
{
    try
    {
        f();
    }
    catch(invalid_argument& err)
    {
        cout << "Error: " << err.what() << endl;
        return -1;
    }
    return 0;
}