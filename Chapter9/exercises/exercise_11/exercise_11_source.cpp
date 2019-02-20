
#include "exercise_11.h"

/** Compares equality of two dates*/
bool operator==(const Chrono::Date &a, const Chrono::Date &b)
{
    if (a.day() == b.year() and a.month() == b.month() and a.year() == b.year())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** Compares inequality of two dates*/
bool operator!=(const Chrono::Date &a, const Chrono::Date &b)
{
    return not operator==(a, b);
}

/** Outputs a date object*/
ostream& operator<<(ostream& out, const Chrono::Date &d)
{
    out << '(' << d.day() << ',' << int(d.month()) << ',' << d.year() << ')';
    return out;
}

/** Inputs a date object*/
istream& operator>>(istream& in, Chrono::Date &dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    in >> ch1 >> d >> ch2 >> m >> ch3 >> y >> ch4;
    if (!in)
    {
        return in;
    }
    if (ch1 != '(' and ch2 != ',' and ch3 != ',' and ch3 != ')')
    {
        in.clear(ios_base::failbit);
        return in;
    }
    dd = Chrono::Date(y, Chrono::Month(m), d);
    return in;        
}


namespace Chrono
{
    /** Default date object*/
    const Date& Date::defaultDate()
    {
        static Date dd;
        return dd;
    }

    /** Default constructor */
    Date::Date() : y(2001), m(Month::jan), d(1)
    {
        if (!isDate(*this))
        {
            throw invalid();
        }
    }

    /** Constructor for a date object*/
    Date::Date(int yy, Month mm, int dd)
        :y(yy), m(mm), d(dd)
    {
        if (!isDate(*this))
        {
            throw invalid();
        }
    }

    /** Copy constructor */
    Date::Date(const Date &other) : y(other.y), m(other.m), d(other.d)
    {}

    /** Returns date objects year value*/
    int Date::year() const
    {
        return this->y;
    }

    /** Returns date objects month value*/
    Month Date::month() const
    {
        return this->m;
    }

    /** Returns date objects day value*/
    int Date::day() const
    {
        return this->d;
    }

    /** Adds n years to year value*/
    void Date::addYear(int n)
    {
        if (m == Month::feb and d == 29 and !leapYear(y + n))
        {
            m = Month::mar;
            d = 1;
        }
        y+=n;
        isDate(*this);
    }

    /** Adds n months to month value*/
    void Date::addMonth(int n)
    {
        int yearsPassed = (int(m) + n) / 12;
        m = Month(int(m) + n % 12);
        if (d > numberDays(month(), year()))
        {
            d = numberDays(month(), year());
        }
        addYear(yearsPassed);
        isDate (*this);
    }

    /** Adds n days to day value*/
    void Date::addDay(int n)
    {
        int daysLeftToAdd = n;
        skipToNextMonth(daysLeftToAdd);  
        d += daysLeftToAdd;   
        isDate (*this);
    }

    /** Returns the number of days in dates month m*/
    int numberDays(const Month m, const int y)
    {
        if (m == Month::jan or m == Month::mar or m == Month::may or m == Month::jul or m == Month::aug
        or m == Month::oct or m == Month::dec)
        {
            return 31;
        }
        else if (m == Month::apr or m == Month::jun or m == Month::sep or m == Month::nov)
        {
            return 30;
        }
        else if (m == Month::feb)
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

    /** Skips month if adding more days than in that month and removes used days*/
    void Date::skipToNextMonth(int &n)
    {
        if (day() + n > numberDays(month(), year()))
        {
            int daysLeftInMonth = numberDays(month(), year()) - day();
            n -= daysLeftInMonth;
            addMonth(1);
            d = 0;
            skipToNextMonth(n);
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

    /** checks Date is invariant*/
    bool isDate(Date &d)
    {
        // assume year is valid

        if(d.day() <= 0 or d.day() > numberDays(d.month(), d.year()))
        {
            return false;
            cout << endl << "ERROR: DAY VALUE CORRUPTED." << endl;
        }
        if (d.month() < Month::jan or d.month() > Month::dec)
        {
            return false;
            cout << endl << "ERROR: MONTH VALUE CORRUPTED." << endl;
        }
        return true;
    }

    /** Returns the next workday*/
    Date nextWorkday(const Date &d)                                
    {                                                                    
        if (dayOfWeek(d) != Day::fri and dayOfWeek(d) != Day::sat)
        {
            Date dd = d;
            dd.addDay(1);
            return dd;                         
        }
        else if (dayOfWeek(d) == Day::fri)
        {
            Date dd = d;
            dd.addDay(3);
            return dd;
        }
        else 
        {
            Date dd = d;
            dd.addDay(2);
            return dd;
        }
    }


    /** Returns the day of the week via Zellers rule method
     *  (e.g. see http://www.quickermaths.com/zellers-rule/)
     * 
    */
    Day dayOfWeek(const Date &d)
    {
        double zellerMonthNumber = zellerNumber(d.month());
        double lastTwoDigitsYear = lastTwoDigits(d.year());
        double centuryDigitsYear = notLastTwoDigits(d.year());
        double day = (d.day());

        // if jan or feb this is treated as the previous year
        if (d.month() == Month::jan or d.month() == Month::feb)
        {
            lastTwoDigitsYear -= 1;
        }

        // method truncates, so integer truncation valid
        int zellerSum = day + ((13 * zellerMonthNumber - 1) / 5.0) + 
                        lastTwoDigitsYear + (lastTwoDigitsYear / 4.0) + 
                        (centuryDigitsYear / 4.0) -
                        2 * centuryDigitsYear;

        // using + to ensure result is always positive
        int dayNumber = +zellerSum % 7;

        return Day(dayNumber);
    }

    /** Returns last two digits of a number*/
    int lastTwoDigits(const int y)
    {
        string year = to_string(y);
        string lastTwoDigits;
        lastTwoDigits.push_back(year[year.size() - 2]);
        lastTwoDigits.push_back(year[year.size() - 1]);
        return stoi(lastTwoDigits);
    }

    /** Returns all but the last two digits of a number*/
    int notLastTwoDigits(const int y)
    {
        string year = to_string(y);
        string notLastTwoDigits;
        for (int i = 0; i < year.size() - 2; i++)
        {
            notLastTwoDigits.push_back(year[i]);
        }
        return stoi(notLastTwoDigits);
    }

    /** Returns Zeller month numbers*/
    int zellerNumber(const Month &m)
    {
        switch(m)
        {
            case Month::jan: case Month::feb:
                {
                    return int(m) + 10;
                    break;   
                }
            default:
                {
                    return int(m) - 2;
                }
        }
    }    
 
    /** Returns the week of the year
     * (week 1 is the week containing January 1 and the first day of that week is a sunday)
    */
    int weekOfYear(const Date &d)
    {
        // minus one from d.day because the final day is not over yet
        // + 1 to week so far because year starts at week 1
        int weeksSoFar = (numberDaysYearSoFar(d) + (d.day() - 1)) / 7;
        return weeksSoFar + 1;
    }

    /** Returns the amount of days that have passed since the sunday (begining) of the week containing January 1*/
    int numberDaysYearSoFar(const Date &d)
    {
        int daysYearSoFar = 0;
        for (int i = 0; i < int(d.month()); i++)
        {
            daysYearSoFar += numberDays(Month(i), d.year());
        }
        //days since January 1 + days till previous sunday if January 1 isn't a sunday
        int sunday = int(dayOfWeek(Date(d.year(),Month::jan,1)));
        return daysYearSoFar + int(dayOfWeek(Date(d.year(),Month::jan,1)));
    }
}
