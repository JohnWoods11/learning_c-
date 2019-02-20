#include "../../stdlibfacilities.h"

namespace Chrono
{
    enum class Day
    {
        sun = 0, mon = 1, tue = 2, wed = 3, thur = 4, fri = 5, sat = 6
    };

    enum class Month
    {
        jan = 0, feb = 1, mar = 2, apr = 3, may = 4, jun = 5, jul = 6, aug = 7, sep = 8, oct = 9, nov = 10, dec = 11
    };

    class Date
    {
    public:
        class Invalid{};

        Date();
        Date(long int day);
        Date(const Date &other);
        ~Date();

        Date& operator=(const Date &other);

        int day() const;
        Month month() const;
        int year() const;        

        void addDay(int);
        void addMonth(int);
        void addYear(int);

    private:
        int _day;
    };

    bool isDate(int d);
    bool leapYear(int d);

    Day dayOfWeek(const Date&);
    Date nextSunday(const Date&);
    Date nextWeekday(const Date&);
}


bool operator==(const Chrono::Date&, const Chrono::Date&);
bool operator!=(const Chrono::Date&, const Chrono::Date&);

ostream& operator>>(ostream &out, const Chrono::Date&);
istream& operator<<(istream &in, const Chrono::Date&);