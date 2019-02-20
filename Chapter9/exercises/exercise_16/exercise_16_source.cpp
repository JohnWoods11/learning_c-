#include "exercise_15.h"

/** Default money constructor*/
Money::Money()
:_base_denominator(0)
{
    assertSane();
}


/** Money constructor using cent input*/
Money::Money(int fd, Currency c)
:_base_denominator(fd), _currency(c)
{
    assertSane();
}


/** Money copy constructor*/
Money::Money(const Money &other)
:_base_denominator(other._base_denominator), _currency(other._currency)
{
    assertSane();
}


/** Money destructor*/
Money::~Money()
{}


/** Money assignment operator*/
void Money::operator=(const Money& other)
{
    this->_base_denominator = other._base_denominator;
    this->_currency = other._currency;
    assertSane();
}


/** Money invariant checker*/
bool Money::assertSane() const
{
    if (_base_denominator < 0)
    {
        throw invalid_argument("Balance can not be negative.");
    }
}


/** Returns value of standard denomination in balance
 * truncation removes fractional denomination from value */
long int Money::standardDenominator() const
{
    return _base_denominator / 100;
}


/** Returns value of the fractional denomination remaining in balance after standard ddenomination is accounted for*/
long int Money::fractionalDenominator() const
{
    return _base_denominator - standardDenominator() * 100;
}


/** Returns currency type of money object*/
Currency Money::currency() const
{
    return _currency;
}


/** Money addition operator*/
Money Money::operator+(const Money &other)
{
    assertSameCurrency(other);
    Money m;
    m._currency = this->_currency;
    m._base_denominator = this->_base_denominator + other._base_denominator;
    m.assertSane();
    return m;
}


/** Money subtraction operator*/
Money Money::operator-(const Money &other)
{
    assertSameCurrency(other);
    Money m;
    m._currency = this->_currency;
    m._base_denominator = this->_base_denominator - other._base_denominator;
    m.assertSane();
    return m;
}


/** Money multiplication operator*/
Money Money::operator*(const double d)
{
    Money m;
    m._currency = this->_currency;
    m._base_denominator = round(this->_base_denominator * d);
    m.assertSane();
    return m;   
}


/** Money output operator*/
ostream& operator<<(ostream& out, const Money &m)
{
    map<int, string> CurrencyName;                           // Why can't i initialise this globaly?
    CurrencyName[0] = "USD";
    CurrencyName[1] = "DSK";
    CurrencyName[2] = "GBP";
    CurrencyName[3] = "JPY";
    out << CurrencyName.at(int(m.currency())) << m.standardDenominator() << ".";
    // force print empty dec value of fractionalDenominator
    if (m.fractionalDenominator() < 10)
    {
        out << 0;
    }
    out << m.fractionalDenominator();
    return out;
}


/** Money intput operator*/
istream& operator>>(istream& in, Money &m)
{
    long int sd, fd;
    Currency currency;
    char ch;
    in >> currency >> sd >> ch >> fd;
    if (!in)
    {
        return in;                                        // coppied the books approach in the library class but should i just throw errors here?
    }
    if (ch !=  '.')
    {
        in.clear(ios_base::failbit);                      // and here
        return in;
    }
    m = Money(sd * 100 + fd, currency);
    return in;
}


/** Currency input operator*/
istream& operator>>(istream& in, Currency &c)
{
    char ch1, ch2, ch3;
    in >> ch1 >> ch2 >> ch3;
    if (!in)
    {
        return in;
    }

    string currency_name;
    currency_name.push_back(ch1);
    currency_name.push_back(ch2);
    currency_name.push_back(ch3);

    map<string, int> CurrencyID;                           // Why can't i initialise this globaly?
    CurrencyID["USD"] = 0;
    CurrencyID["DSK"] = 1;
    CurrencyID["GBP"] = 2;
    CurrencyID["JPY"] = 3;

    if (CurrencyID.count(currency_name) == 0)
    {
        in.clear(ios_base::failbit);
        return in;
    }
    c = Currency(CurrencyID.at(currency_name));
    return in;
}


/** Asserts same currency is being useed*/
bool Money::assertSameCurrency(const Money &other) const                                    // should this be void and just return instead of
{                                                                                           // retuning true?
    if (this->_currency == other._currency)
    {
        return true;
    }
    throw invalid_argument("Can not operate using two different currencys.");
}
