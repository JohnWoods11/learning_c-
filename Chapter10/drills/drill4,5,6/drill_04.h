#include "../../stdlibfacilities.h"

class Point
{
public:
    Point();
    Point(double x, double y);
    Point(const Point &other);
    ~Point();

    void operator=(const Point &other);

    double x() const;
    double y() const;

private:
    double x_Value;
    double y_Value;
};

istream& operator>>(istream &in, Point &p);
ostream& operator<<(ostream &out, const Point &p);