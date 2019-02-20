#include "exercise_10.h"

namespace Chrono
{

    /** Constructor for a date object*/
    Date::Date(int yy, Month mm, int dd)
    :y(yy), m(mm), d(dd)
    {
        if (!isDate(*this))
        {
            throw invalid();
        }
    }

    /** Default constructor for a date object*/
    Date::Date()
    :y{defaultDate().year()},
    m{defaultDate().month()},
    d{defaultDate().day()}
    {}

    /** Default date object*/
    const Date Date::defaultDate()
    {
        static Date dd(2001, Month::jan, 1);
        return dd;
    }

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
        if (d > numberDays(*this))
        {
            d = numberDays(*this);
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
    int numberDays(const Date &d)
    {
        if (d.month() == Month::jan or d.month() == Month::mar or d.month() == Month::may or d.month() == Month::jul or d.month() == Month::aug
        or d.month() == Month::oct or d.month() == Month::dec)
        {
            return 31;
        }
        else if (d.month() == Month::apr or d.month() == Month::jun or d.month() == Month::sep or d.month() == Month::nov)
        {
            return 30;
        }
        else if (d.month() == Month::feb)
        {
            if (leapYear(d.year()))
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
        if (day() + n > numberDays(*this))
        {
            int daysLeftInMonth = numberDays(*this) - day();
            n -= daysLeftInMonth;
            addMonth(1);
            d = 0;
            skipToNextMonth(n);
        }
    }

    /** Compares equality of two dates*/
    bool operator==(const Date &a, const Date &b)
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
    bool operator!=(const Date &a, const Date &b)
    {
        return not operator==(a, b);
    }

    /* Checks if year is a leap year*/
    bool leapYear(const int y)
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

    /** Outputs a date object*/
    ostream& operator<<(ostream& out, const Date &d)
    {
        out << '(' << d.day() << ',' << int(d.month()) << ',' << d.year() << ')';
        return out;
    }

    /** Inputs a date object*/
    istream& operator>>(istream& in, Date &dd)
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
        dd = Date(y, Month(m), d);
        return in;        
    }

    /** checks Date is invariant*/
    bool isDate(Date &d)
    {
        // assume year is valid

        if(d.day() <= 0 or d.day() > numberDays(d))
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
}
