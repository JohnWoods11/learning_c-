#include "drill_04.h"



/** Default constructor*/
Point::Point()
:x_Value(0), y_Value(0)
{}


/** Constructor*/
Point::Point(double x_value, double y_value)
:x_Value(x_value), y_Value(y_value)
{}


/** Copy constructor*/
Point::Point(const Point &other)
:x_Value(other.x_Value), y_Value(other.y_Value)
{}


/** Destructor*/
Point::~Point()
{}


/** Copy assignment operator*/
void Point::operator=(const Point &other)
{
    this->x_Value = other.x_Value;
    this->y_Value = other.y_Value;
}



/** Return x value*/
double Point::x() const
{
    return x_Value;
}


/** Return y value*/
double Point::y() const
{
    return y_Value;
}




/** Input operator for a point*/
istream& operator>>(istream &in, Point &p)
{
    double x, y;
    char ch1, ch2, ch3;
    in >> ch1 >> x >> ch2 >> y >> ch3;
    if (!in)
    {
        return in;
    }
    if (ch1 != '(' or ch2 != ',' or ch3 != ')')
    {
        in.clear(ios_base::failbit);
        return in;
    }
    Point t(x,y);
    p = t;
    return in;
}


/** Output operator*/
ostream& operator<<(ostream& out, const Point &p)
{
    out << '(' << p.x() << ',' << p.y() << ')';
    return out;
}
