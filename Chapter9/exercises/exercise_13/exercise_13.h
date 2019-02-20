#include "../../stdlibfacilities.h"

class Rational
{
public:
    Rational();
    Rational(int, int);
    Rational(const Rational&);
    ~Rational();

    bool isRational() const;
    int top() const;
    int bottom() const;

    bool operator==(const Rational&) const;             //should these be outside of class?
    bool operator!=(const Rational&) const;

    void operator=(const Rational&);

    Rational operator+(const Rational&);
    Rational operator-(const Rational&);
    Rational operator*(const Rational&);
    Rational operator/(const Rational&);

    double convertToDouble();


private:
    int _top;
    int _bottom;
};

ostream& operator<<(ostream &out, const Rational&);
istream& operator>>(istream &in, Rational&);
