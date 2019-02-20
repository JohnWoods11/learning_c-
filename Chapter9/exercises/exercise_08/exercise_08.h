#include "../../stdlibfacilities.h"
#include <cctype>


class Patron
{
public:
    Patron(string n, string cardnum, double cred);
    Patron(const Patron &other);
    ~Patron();

    void setFee(double);
    double seeCredit() const;
    string seeName() const;
    string seeCardNumber() const;

private:
    string name;
    string cardNumber;
    double credit;
};

bool patronOwesFee(const Patron &customer);

enum class Genre
{ 
    fiction, nonfiction, periodical, biography, children                                // What if i included the enum in the class
};                                                                                      // could I then not just initialise with 'fiction'
                                                                                        // instead of Genre::fiction?
class ISBN
{
public:
    ISBN(char a, char b, char c, char d);
    ~ISBN();
    string isbn() const;

private:
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
    book(string tit, string auth, Genre genre, ISBN ident, date copyright);
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
    Genre genre;
    date copyrightDate;
    ISBN identifier;
    bool checkedIn;
};

ostream& operator<<(ostream &out, const book &books);