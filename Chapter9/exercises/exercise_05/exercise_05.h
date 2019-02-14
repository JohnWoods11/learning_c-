#include "../../stdlibfacilities.h"
#include <cctype>

class ISBN
{
public:
    ISBN(char a, char b, char c, char d);
    ~ISBN();
    string isbn();

private:
    char first;
    char second;
    char third;
    char fourth;
    string completeISBN;
};

class date
{
public:
    date(int dd, int mm, int yy);
    ~date();
private:
    int d;
    int m;
    int y;
};


class book
{
public:
    book(string tit, string auth, ISBN ident, date copyright);
    book(const book &other);
    ~book();

    string thisISBN();
    string thisAuthor();
    string thisTitle();
    date thisCopyDate();
    bool isCheckedIn();

    void checkOut();
    void checkin();

private:
    void setCheckInStatus();
    string title;
    string author;
    date copyrightDate;
    ISBN identifier;
    bool checkedIn;
};


