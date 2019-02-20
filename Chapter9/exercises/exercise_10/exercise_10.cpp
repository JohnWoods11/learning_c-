#include "exercise_10.h"
using namespace Chrono;

void f()
{
    Date yesterday(2019,Month::feb,15);
    Date today(2020,Month::feb,16);
    cout << today << endl;
    today.addDay(5);
    cout << today << endl;
    today.addDay(20);
    cout << today << endl;
    today.addMonth(5);
    cout << today << endl;
    if (today != yesterday)
    {
        cout << today << " is not the same as " << yesterday << endl;
    }
    if (leapYear(today.year()))
    {
        cout << today.year() << " is a leap year." << endl;
    }
    if (!leapYear(today.year()))
    {
        cout << today.year() << " is not a leap year" << endl;
    }
    today.addYear(1);
     if (leapYear(today.year()))
    {
        cout << today.year() << " is a leap year." << endl;
    }
    if (!leapYear(today.year()))
    {
        cout << today.year() << " is not a leap year" << endl;
    }
    cout << today << endl;
}

int main()
{
    try
    {
        f();
    }
    catch(...)
    {
        cout << "Fatal error." << endl;
    }
    
}