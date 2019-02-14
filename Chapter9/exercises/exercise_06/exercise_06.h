#include "../../stdlibfacilities.h"
#include <cctype>

class ISBN
{
public:
    ISBN(char a, char b, char c, char d);
    ~ISBN();
    string isbn() const;

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

    
    bool operator!=(const book &other) const;
    bool operator==(const book &other) const;
    string thisISBN() const;
    string thisAuthor() const;
    string thisTitle() const;
    date thisCopyDate() const;
    bool isCheckedIn() const;

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

ostream& operator<<(ostream &out, const book &books);