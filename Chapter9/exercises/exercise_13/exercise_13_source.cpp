#include "exercise_13.h"


/** Default constructor*/
Rational::Rational()
:_top(1), _bottom(1)
{
    isRational();
}


/** Constructor*/
Rational::Rational(int t, int b)
:_top(t), _bottom(b)
{
    isRational();
}


/** Copy constructor*/
Rational::Rational(const Rational& other)
:_top(other._top), _bottom(other._bottom)
{
    isRational();
}


/** Destructor*/
Rational::~Rational()
{}


/** Invariant test*/
bool Rational::isRational() const
{
    if (_bottom == 0)
    {
        throw invalid_argument("The second integer in a rational can not be 0.");
    }
}


/** Equality operator*/
bool Rational::operator==(const Rational &other) const
{
    if (this->_top == other._top and this->_bottom == other._bottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/** Inequality operator*/
bool Rational::operator!=(const Rational &other) const
{
    return !operator==(other);
}


/** Assignment operator*/
void Rational::operator=(const Rational &other)                                //is this right?
{
    this->_top = other._top;
    this->_bottom = other._bottom;
}


/** Addition operator for a rational*/
Rational Rational::operator+(const Rational &other)
{
    Rational r;
    r._top = this->_top * other._bottom + other._top * this->_bottom;
    r._bottom = this->_bottom * other._bottom;
    return r;
}


/** Subtraction operator for a rational*/
Rational Rational::operator-(const Rational &other)
{
    Rational r;
    r._top = this->_top - other._bottom + other._top * this->_bottom;
    r._bottom = this->_bottom * other._bottom;
    return r;
}


/** Multiplication operator for a rational*/
Rational Rational::operator*(const Rational& other)
{
    Rational r;
    r._top = this->_top * other._top;
    r._bottom = this->_bottom * other._bottom;
    return r;
}


/** Division operator for a rational*/
Rational Rational::operator/(const Rational& other)
{
    Rational r;
    r._top = this->_top * other._bottom;
    r._bottom = this->_bottom * other._top;
    return r;
}


/** Return top value*/
int Rational::top() const
{
    return _top;
}


/** Return bottom value*/
int Rational::bottom() const
{
    return _bottom;
}

/** Convert rational to a double*/
double Rational::convertToDouble()
{
    double d = this->_top / this->_bottom;
    return d;
}


/** Output operator for a rational*/
ostream& operator<<(ostream &out, const Rational &r)
{
    out << r.top() << "/" << r.bottom();
    return out;
}


/** Input operator for a rational*/
istream& operator>>(istream &in, Rational &r)
{
    int t, b;
    char ch;
    in >> t >> ch >> b;
    if (!in)
    {
        return in;
    }
    if (ch != '/')
    {
        in.clear(ios_base::failbit);
        return in;
    }
    Rational rr(t, b);
    r = rr;
    return in;
}

