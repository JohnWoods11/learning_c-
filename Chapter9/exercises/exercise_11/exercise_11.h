#include "../../stdlibfacilities.h"

#include <map>

namespace Chrono
{
    enum class Month
    {
        jan = 1, feb = 2, mar = 3, apr = 4, may = 5, jun = 6, jul = 7, aug = 8, sep = 9, oct = 10, nov = 11, dec = 12        // Month is an object and it's enum is 1-12. But can i give them member
    };                                                                        // data?

    enum class Day
    {
        sun, mon, tue, wed, thur, fri, sat
    };

    class Date
    {
    public:
        class invalid{};

        Date();
        Date(int y, Month m, int d);
        Date(const Date &other);

        int day() const;
        Month month() const;
        int year() const;
        static const Date& defaultDate();
    
        void addDay(int);
        void addMonth(int);
        void addYear(int);
    private:
        void skipToNextMonth(int&);
        int y;
        Month m;
        int d;
    };

    bool isDate(Date &d);
    bool leapYear(const int y);
    int numberDays(const Month m, const int y);
    Date nextWorkday(const Date &d);
    Day dayOfWeek(const Date &d);
    int lastTwoDigits(const int y);
    int notLastTwoDigits(const int y);
    int zellerNumber(const Month &m);
    int weekOfYear(const Date &d);
    int numberDaysYearSoFar(const Date &d);

} // End of chrono namespace

bool operator==(const Chrono::Date &a, const Chrono::Date &b);
bool operator!=(const Chrono::Date &a, const Chrono::Date &b);

ostream& operator<< (ostream &out, const Chrono::Date &d);
istream& operator>> (ostream &in, Chrono::Date &dd);
