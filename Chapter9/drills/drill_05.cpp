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
    int year() const
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
    Date()
    : y{Year(1800)}, m{Month::jan}, d{1}{}
    Date(Year yy, Month mm, int dd)
    : y{yy}, m{mm}, d{dd}
    {
        if (d < 1 or d > 31)
        {
            throw invalid_argument("no month has a day " + to_string(d));
        }
    }

    int day() const {return d;}
    Month month() const {return m;}
    Year year() const {return y;}
    vector<string> months {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    void add_day(int);
    void add_month(int);
    void add_year(int);
private:
    int d;
    Month m;
    Year y;
};
void Date::add_day(int n)
{
    for (int i = 0; i < n; i++)
    {
        d = (d == 31) ? d = 1 : d + 1;
        if (d == 1)
        {
            add_month(1);
        }
    }
}

void Date::add_month(int n)
{
    for (int i = 0; i < n; i++)
    {
        m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
        if (m == Month::jan)
        {
            add_year(1);
        }
    }
}

void Date::add_year(int n)
{
    y = Year(y.year() + 1);
}

void f()
{
    Date today(Year(2000), Month::mar, 12);
    cout << today.day() << " " << today.months[int(today.month()) + 1] << " " << today.year().year() << endl;
    today.add_day(30);
    cout << today.day() << " " << today.months[int(today.month()) + 1] << " " << today.year().year() << endl;
    today.add_month(10);
    cout << today.day() << " " << today.months[int(today.month()) + 1] << " " << today.year().year() << endl;
    today.add_year(10);
    cout << today.day() << " " << today.months[int(today.month()) + 1] << " " << today.year().year() << endl;
}
/*
Day, Month, Year

Date = Day + Month, Month + Day, Date + Year, Month + Year, 

f = Month("February");
d = Day(29);
y = Year(2004);

d = Date(Year(2004), Month("February"), Day(29));

TimeDelta = Date - Date

TimeDelta.hours(), .days(), 
*/

int main()
{
    try
    {
        f();
    }
    catch(...)
    {
        cout << "MAJOR ERROR";
    }
}