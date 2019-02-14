#include "exercise_06.h"

const int currentYear = 2019;

/** Prints title author and ISBN of a book*/
ostream& operator<<(ostream &out, const book &books)
{
    out << books.thisTitle() << endl << books.thisAuthor() << endl << books.thisISBN() << endl;
    return out;
}

/** Constructor for a book*/
book::book(string tit, string auth, ISBN ident, date copyright)
: title(tit), author(auth), identifier(ident), copyrightDate(copyright)
{
    setCheckInStatus();
}

/** Copy constructor for a book*/
book::book(const book &other)
:title(other.title), author(other.author), identifier(other.identifier), copyrightDate(other.copyrightDate)
{
    setCheckInStatus();
}

/** Deconstructor for book*/
book::~book()
{}

/** Initialises checked in status*/
void book::setCheckInStatus()
{
    cout << "Is this book checked in? (y , n)";
    while (true)
    {
        string input;
        cin >> input;
        if (input == "y")
        {
            checkedIn = true;
            break;
        }
        if (input == "n")
        {
            checkedIn = false;
            break;
        }
        cout << "Please enter either 'y' (yes) or 'n' (no)";
    }
}

/** Compares equality of the ISBNs of two books*/
bool book::operator==(const book &other) const
{
    if (this->thisISBN().compare(other.thisISBN()) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** Compares inequality of the ISBNs of two books*/
bool book::operator!=(const book &other) const
{
    return not this->operator==(other);
}


/** Check in a book*/
void book::checkin()
{
    try
    {
        if (this->checkedIn != true)
        {
            this->checkedIn = true;
        }
        else
        {
            throw invalid_argument(this->title + " is already checked in." );
        }
    }
    catch (invalid_argument &err)
    {
        cout << "Error:" << err.what();
    }
}

/** Check out a book*/
void book::checkOut()
{
    try
    {
        if (this->checkedIn != false)
        {
            this->checkedIn = false;
        }
        else
        {
            throw invalid_argument(this->title + " is already checked out.");
        }
    }
    catch (invalid_argument &err)
    {
        cout << "Error:" << err.what();
    }
}

/** Return true if book is currently checked in or false if not*/
bool book::isCheckedIn() const
{
    return checkedIn;
}

/** Return the ISBN of the book*/
string book::thisISBN() const
{
    return this->identifier.isbn();
}

/** Return the title of the book*/
string book::thisTitle() const
{
    return this->title;
}   

/** Return the author of the book*/
string book::thisAuthor() const
{
    return this->author;
}

/** Return the copyright date of the book*/
date book::thisCopyDate() const
{
    return this->copyrightDate;
}

/** Constructor for a ISBN code*/
ISBN::ISBN(char a, char b, char c, char d)
:first(a), second(b), third(c), fourth(d)
{
    try
    {   
        if (isdigit(a) == false or isdigit(b) == false or isdigit(c) == false or isalnum(d) == false)
        {
            throw invalid_argument(" the first three characters of an ISBN must be numeric and the last alphanumeric.");
        }
        completeISBN.push_back(a);
        completeISBN.push_back(b);
        completeISBN.push_back(c);
        completeISBN.push_back(d);
    }
    catch (invalid_argument &err)
    {
        cout << "Error:";
    }
}

/** Destructor for an ISBN code*/
ISBN::~ISBN()
{}

/** Returns private ISBN as a string*/
string ISBN::isbn() const
{
    return this->completeISBN;
}

date::date(int dd, int mm, int yy)
: d(dd), m(mm), y(yy)
{
    try
    {
        if (d > 31 or d < 1 or m > 12 or m < 1 or y > currentYear)
        {
            throw invalid_argument(" date not accepted.");
        }
    }
    catch (invalid_argument &err)
    {
        cout << "Error: ";
    }
}

date::~date()
{}


