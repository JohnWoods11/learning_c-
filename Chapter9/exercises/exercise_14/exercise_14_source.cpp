#include "exercise_14.h"
#include <cmath>

/** Default money constructor*/
Money::Money()
:_cents(0)
{
    assertSane();
}


/** Money constructor using cent input*/
Money::Money(int c)
:_cents(c)
{
    assertSane();
}


/** Money copy constructor*/
Money::Money(const Money &other)
:_cents(other._cents)
{
    assertSane();
}


/** Money destructor*/
Money::~Money()
{}


/** Money assignment operator*/
void Money::operator=(const Money& other)
{
    this->_cents = other._cents;
    assertSane();
}


/** Money invariant checker*/
bool Money::assertSane() const
{
    if (_cents < 0)
    {
        throw invalid_argument("Balance can not be negative.");
    }
}


/** Returns number of dollars in balance
 * truncation removes cents from value */
long int Money::dollars() const
{
    return _cents / 100;
}


/** Returns number of _cents remaining in balance after dollars are accounted for*/
long int Money::cents() const
{
    return _cents - dollars() * 100;
}


/** Money addition operator*/
Money Money::operator+(const Money &other)
{
    Money m;
    m._cents = this->_cents + other._cents;
    m.assertSane();
    return m;
}


/** Money subtraction operator*/
Money Money::operator-(const Money &other)
{
    Money m;
    m._cents = this->_cents - other._cents;
    m.assertSane();
    return m;
}


/** Money multiplication operator*/
Money Money::operator*(const double d)
{
    Money m;
    m._cents = round(this->_cents * d);
    assertSane();
    return m;   
}


/** Money output operator*/
ostream& operator<<(ostream& out, const Money &m)
{
    out << '$' << m.dollars() << ".";
    // force print empty dec value of cents
    if (m.cents() < 10)
    {
        out << 0;
    }
    out << m.cents();
    return out;
}


/** Money output operator*/
istream& operator>>(istream& in, Money &m)
{
    long int d, c;
    char ch1, ch2;
    in >> ch1 >> d >> ch2 >> c;
    if (!in)
    {
        return in;                                        // coppied the books approach in the library class but should i just throw errors here?
    }
    if (ch1 != '$' and ch2 != '.')
    {
        in.clear(ios_base::failbit);                      // and here
        return in;
    }
    m = Money(d+c);
    return in;
}
