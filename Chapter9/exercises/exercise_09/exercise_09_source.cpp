#include "exercise_09.h"

const int currentYear = 2019;

/** Prints title author and ISBN of a book*/
ostream& operator<<(ostream &out, const Book &books)
{
    out << books.title() << endl << books.author() << endl << books.isbn() << endl;
    return out;
}

/** Constructor for a book*/
Book::Book(string tit, string auth, Genre gen, ISBN ident, Date copyright)
: title(tit), author(auth), genre(gen), identifier(ident), copyrightDate(copyright)
{
    setCheckInStatus();
}

/** Copy constructor for a book*/
Book::Book(const Book &other)
:title(other.title), author(other.author), genre(other.genre), identifier(other.identifier), copyrightDate(other.copyrightDate),
checkedIn(other.checkedIn)
{}

/** Deconstructor for book*/
Book::~Book()
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
    if (this->isbn().compare(other.isbn()) == 0)
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
string book::isbn() const
{
    return this->identifier.isbn();
}

/** Return the title of the book*/
string book::title() const
{
    return this->title;
}   

/** Return the author of the book*/
string book::author() const
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

/** Date constructor*/
date::date(int dd, int mm, int yy)
: d(dd), m(mm), y(yy)
{
    if (d > 31 or d < 1 or m > 12 or m < 1 or y > currentYear)
    {
        throw invalid_argument(" date not accepted.");
    }
}

/** Date destructor*/
date::~date()
{}

/** Patron constructor*/
Patron::Patron(string n, string cardnum, double balance)
: name(n), cardNumber(cardnum), credit(balance)
{
    try
    {
        if (balance < 0)
        {
            throw invalid_argument(" user fees can not be negative.");
        }
    }
    catch (invalid_argument &err)
    {
        cout << "Error:" << err.what() << endl;
    }
}

/** Patron copy constructor*/
Patron::Patron(const Patron &other)
{
    name = other.name;
    cardNumber = other.cardNumber;
    credit = other.credit;
}

/** Patron deconstructor*/
Patron::~Patron()
{}

/** Compares equality of two Patrons*/
bool Patron::operator==(const Patron &other) const
{
    if (this->name == other.name and this->cardNumber == other.cardNumber)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** Set the patrons fee amount*/
void Patron::setFee(double amount)
{
    try
    {
        if (amount < 0)
        {
            throw invalid_argument(" user fees can not be negative.");
        }
        this->credit = amount;
    }
    catch (invalid_argument &err)
    {
        cout << "Error:" << err.what() << endl;
    }
}

/** Returns user name*/
string Patron::seeName() const
{
    return this->name;
}

/** Returns user card number*/
string Patron::seeCardNumber() const
{
    return this->cardNumber;
}

/** Returns user fee amount*/
double Patron::seeCredit() const
{
    return this->credit;
}

/** Checks if Patron owes fee*/
bool patronOwesFee(const Patron &customer)
{
    if (customer.seeCredit() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** Constructor for a transaction*/
transaction::transaction(const Patron &pp, const book &bb, date dd)
: p(pp), b(bb), d(dd)
{}

/** Destructor for a transaction*/
transaction::~transaction()
{}

/** Constructor for an empty library*/
Library::Library()
{}

/** Deconstructor for a library*/
Library::~Library()
{}

/** adds book to the library */
void Library::addBook(book &b)
{
    books.push_back(b);
}

/** adds a patron to the library*/
void Library::addPatron(Patron &p)
{
    patrons.push_back(p);
}

/** Checks out book in patrons name*/
void Library::checkOutBook(const Patron &p, book &b)
{
    try
    {
        checkElegibility(b, p);
        storeTransaction(b, p);
        b.checkOut();
    }
    catch (invalid_argument &err)
    {
        cout << "Error:" << err.what() << endl;
    }
}

/** Returns all the patrons who owe fees*/
vector<Patron> Library::whoOwesFees() const
{
    vector<Patron> feeOwers;
    for (auto patron:patrons)
    {
        if (patronOwesFee(patron))
        {
            feeOwers.push_back(patron);
        }
    }
    return feeOwers;
}

/** Stores checkout transaction data*/
void Library::storeTransaction(const book &b, const Patron &p)
{
    int dd;
    int mm;
    int yy;
    cout << "Please enter todays numeric date (dd mm yy): ";
    cin >> dd >> mm >> yy;
    transactons.push_back(transaction(p, b, date(dd, mm, yy)));
}

/** Check elegibility of patron to check out book*/
void Library::checkElegibility(const book &b, const Patron &p) const
{
    patronInLibrary(p);
    bookInLibrary(b);
    if (not b.isCheckedIn())
    {
        throw invalid_argument(" book is currently checked out.");
    }
    if (patronOwesFee(p))
    {
        throw invalid_argument( " " + p.seeName() + " owes a fee.");
    }
}

/** Checks if patron is library member*/
void Library::patronInLibrary(const Patron &p) const
{
    for (auto patron:patrons)
    {
        if (p == patron)
        {
        return;
        }
    }
    throw invalid_argument( " " + p.seeName() + " is not a member of the library.");
}

/** Checks if the book is in the library*/
void Library::bookInLibrary(const book &b) const
{
    for (auto book:books)
    {
        if (b == book)
        {
            return;
        }
    }
    throw invalid_argument( " the library does not have the book " + b.title());
}

/** Returns all past transactions*/
vector<transaction> Library::transactionLedger() const
{
    return transactons;
}