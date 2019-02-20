#include "exercise_12.h"


/** Default date constructor*/
Chrono::Date::Date()
:_day(0)
{
    if (!isDate(_day))
    {
        throw Invalid();
    }
}

/** Date constructor*/
Chrono::Date::Date(long int n)
:_day(n)
{
    if (!isDate(_day))
    {
        throw Invalid();
    }
}


/** Copy constructor for a date class*/
Chrono::Date::Date(const Date &other)
:_day(other._day)
{
    if (!isDate(_day))
    {
        throw Invalid();
    }
}


/** Date destructor*/
Chrono::Date::~Date()
{}


/** Date assignment operator*/
Chrono::Date& Chrono::Date::operator=(const Date &other)
{
    Date dd(other);
    return dd;
}


/** Returns the numerical day of the month*/
int Chrono::Date::day() const
{
    return _day;
}


/** Returns the month of the year*/
Chrono::Month Chrono::Date::month() const 
{
    int accumalitive_month_days = 0;
    for (int i = 0; ; i++)
    {
        accumalitive_month_days += numberDays(Chrono::Month(i), year());
        if (accumalitive_month_days > _day - year() / 4)

    }

}


/** Returns the year*/
int Chrono::Date::year() const
{
    int year_of_block;
    // Where is the the day in its four year block
    int remainder_four_years = _day % 1461;
    if (remainder_four_years > 365)
    {
        year_of_block = 1;
    }
    else if (remainder_four_years > 730)
    {
        year_of_block = 2;
    }
    else if (remainder_four_years > 1096)
    {
        year_of_block = 3;
    }
    else
    {
        year_of_block = 4;
    }
    int year = (_day - remainder_four_years) / 1461 + year_of_block;
    return year;
}








/** Returns the number of days in dates month m*/
int numberDays(const Chrono::Month m, const int y)
{
    if (m == Chrono::Month::jan or m == Chrono::Month::mar or m == Chrono::Month::may or m == Chrono::Month::jul or m == Chrono::Month::aug
    or m == Chrono::Month::oct or m == Chrono::Month::dec)
    {
        return 31;
    }
    else if (m == Chrono::Month::apr or m == Chrono::Month::jun or m == Chrono::Month::sep or m == Chrono::Month::nov)
    {
        return 30;
    }
    else if (m == Chrono::Month::feb)
    {
        if (leapYear(y))
        {
            return 29;
        }
        else 
        {
            return 28;
        }
    }
}


 /* Checks if year is a leap year*/
    bool leapYear(const int y)
    {
        if (y % 100 == 0 and y % 400 != 0)
            {
                return false;
            }
        else
        {        
            if (y % 4 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }