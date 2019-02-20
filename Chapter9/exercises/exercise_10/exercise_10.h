#include "../../stdlibfacilities.h"

namespace Chrono
{
    enum class Month
    {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec        // Month is an object and it's enum is 1-12. But can i give them member
    };                                                                        // data?


    class Date
    {
    public:
        class invalid{};

        Date(int y, Month m, int d);
        Date();

        int day() const;
        Month month() const;
        int year() const;
        const Date defaultDate();
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
    int numberDays(const Date &d);


    

    bool operator==(const Date &a, const Date &b);
    bool operator!=(const Date &a, const Date &b);

    ostream& operator<< (ostream &out, const Date &d);
    istream& operator>> (ostream &in, Date &dd);
} // End of chrono namespace
