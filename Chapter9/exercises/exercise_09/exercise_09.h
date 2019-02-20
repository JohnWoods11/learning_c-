
#include "../../stdlibfacilities.h"
#include <cctype>


class Patron
{
public:
    Patron();
    Patron(string n, string cardnum, double cred);
    Patron(const Patron &other);
    ~Patron();

    bool operator==(const Patron &other) const;
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
    ISBN();
    ISBN(char a, char b, char c, char d);
    ~ISBN();
    string isbn() const;

private:
    string completeISBN;
};

class Date
{
public:
    Date();
    Date(int dd, int mm, int yy);
    ~Date();
private:
    int d;
    int m;
    int y;
};


class Book
{
public:
    Book();
    Book(string title, string author, Genre genre, ISBN isbn, const Date &copyright);
    Book(const Book &other);
    ~Book();
   
    bool operator!=(const Book &other) const;
    bool operator==(const Book &other) const;
 
    string isbn() const;
    string author() const;
    string title() const;

    const Date& copyright() const;
    bool isCheckedIn() const;

    void checkOut();
    void checkin();

private:
    void setCheckInStatus();

    string _title;
    string _author;
    Genre _genre;
    Date _copyright_date;
    ISBN _identifier;
    bool _checked_in;
};

ostream& operator<<(ostream &out, const Book &books);

class Transaction
{
public:
    Transaction(const Patron &pp, const Book &bb, const Date &dd);
    ~Transaction();

    const Patron& patron() const;
    const Book& book() const;
    const Date& date() const;

private:
    Transaction();
    Transaction(const Transaction &other);
    Transaction& operator=(const Transaction &other);

    Patron p;
    Book b;
    Date d;
};

class Library
{
public:
    Library();
    ~Library();

    void add(Book &b);
    void add(Patron &p);

    void checkOut(const Patron &p, Book &b);

    vector<Patron> whoOwesFees() const;
    vector<Transaction> transactionLedger() const;
    
private:
    void checkElegibility(const Book &b, const Patron &p) const;
    void storeTransaction(const Book &b, const Patron &p);
    void patronInLibrary(const Patron &p) const;
    void bookInLibrary(const Book &b) const;
    vector<Transaction> transactons;
    vector<Book> books;
    vector<Patron> patrons;
};
