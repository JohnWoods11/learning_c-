#include "../stdlibfacilities.h"

struct date
{
    int y, m, d;
    date(int y, int m, int d);
    void add_day(int n);
};

date::date(int init_y, int init_m, int init_d)
{
     if ((init_y < 2100 and init_y > 1900) and (init_m > 0 and init_m < 13) and (init_d > 0 and init_d < 31))
    {
        y = init_y; 
        m = init_m;
        d = init_d;
    }
    else 
    throw invalid_argument("Bad date");
}

void date::add_day(int n)
{
    if (d == 31)
    {
        if (m == 12)
        {
            d = 1;
            m = 1;
            y += 1;
        }
        else
        {    
        d = 1;
        m += 1;
        }
    }
    else
    {
        d += 1;
    }
}

void f()
{
    date today(12, 24, 2004);
}

int main()
{
    try
    {
        f();
    }
    catch (invalid_argument& err)
    {
        cout << "Error: " << err.what() << endl;
    }
}