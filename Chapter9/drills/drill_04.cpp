#include "../stdlibfacilities.h"

class Year
{
public:
    class invalid{};
    Year(int x) : y(x) 
    { 
        if (x < min or x > max) 
            throw invalid();
    }
    int year()
    {
        return y;
    }
private:
    static const int min = 1800;
    static const int max = 2200;
    int y;
};


enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date
{
public:
    Date(Year yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
    {
        if (d < 1 or d > 31)
        {
            throw invalid_argument("bad date");
        }
    }
private:
    Year y;
    Month m;
    int d;
};

void f()
{
    Date today (2009, Month::mar, -2);
}

int main()
{ 
    try
    {
        f();
    }
    catch (const exception& err)
    {
        cout << "Error: " << err.what() << endl; 
    }
}