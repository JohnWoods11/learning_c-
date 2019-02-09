#include "../stdlibfacilities.h"

class Date
{
public:
    Date(int y, int m, int d);
    void add_day(int n);
    int month()
    {
        return m;
    }
    int day()
    {
        return d;
    }
    int year()
    {
        return y;
    }
private:
    int y, m, d;
};

Date::Date(int init_y, int init_m, int init_d)
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


void Date::add_day(int n)
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
    Date today(2005,12,24);
    today.add_day(5);
    cout << today.day() << today.month() << today.year();    
}

int main()
{
    try
    {
        f();
    }
    catch(const std::exception& e)
    {
        cout << "Error: " << e.what() << endl;
        return -1;
    }
    return 0;    
}

