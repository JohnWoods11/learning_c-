#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"
#include "../GUI/std_lib_facilities.h"
#include <iostream>

Point* n(const Circle &c)
{
    Point *p = new Point(c.center().x, c.center().y - c.radius());
    return p;
}

Point* e(const Circle &c)
{
    Point *p = new Point(c.center().x + c.radius(), c.center().y);
    return p;
}

Point* s(const Circle &c)
{
    Point *p = new Point(c.center().x, c.center().y + c.radius());
    return p;
}

Point* w(const Circle &c)
{
    Point *p = new Point(c.center().x - c.radius(), c.center().y);
    return p;
}

Point* n(const Ellipse &e)
{
    Point *p = new Point(e.center().x, e.center().y - e.minor());
    return p;
}

Point* e(const Ellipse &e)
{
    Point *p = new Point(e.center().x + e.major(), e.center().y);
    return p;
}

Point* s(const Ellipse &e)
{
    Point *p = new Point(e.center().x, e.center().y + e.minor());
    return p;
}

Point* w(const Ellipse &e)
{
    Point *p = new Point(e.center().x - e.major(), e.center().y);
    return p; 
}

Point* ne(const Circle &c)
{
    Point *p = new Point(c.center().x + cos(315 * M_PI / 180) * c.radius(), c.center().y + sin(315 * M_PI / 180) * c.radius());
    return p;
}

Point* se(const Circle &c)
{
    Point *p = new Point(c.center().x + cos(45 * M_PI / 180) * c.radius(), c.center().y + sin(45 * M_PI / 180) * c.radius());
    return p;
}

Point* sw(const Circle &c)
{
    Point *p = new Point(c.center().x + cos(135 * M_PI / 180) * c.radius(), c.center().y + sin(135 * M_PI / 180) * c.radius());
    return p;
}

Point* nw(const Circle &c)
{
    Point *p = new Point(c.center().x + cos(225 * M_PI / 180) * c.radius(), c.center().y + sin(225 * M_PI / 180) * c.radius());
    return p;
}

Point* ne(const Ellipse &e)
{
    //double radius = (e.major() * e.minor()) / (sqrt(pow(e.minor(), 2)*pow(sin(45* M_PI / 180), 2) + pow(e.major(), 2)*pow(cos(45* M_PI / 180), 2)));
    //cout << radius;
    Point *p = new Point(e.center().x + cos(45 * M_PI / 180) * e.radius(45), e.center().y - sin(45 * M_PI / 180) * e.radius(45));
    return p;
}

Point* se(const Ellipse &e)
{
    Point *p = new Point(e.center().x + cos(315 * M_PI / 180) * e.radius(315), e.center().y - sin(315 * M_PI / 180) * e.radius(315));
    return p;
}

Point* sw(const Ellipse &e)
{
    Point *p = new Point(e.center().x + cos(225 * M_PI / 180) * e.radius(225), e.center().y - sin(225 * M_PI / 180) * e.radius(225));
    return p;
}

Point* nw(const Ellipse &e)
{
    Point *p = new Point(e.center().x + cos(135 * M_PI / 180) * e.radius(135), e.center().y - sin(135 * M_PI / 180) * e.radius(135));
    return p;
}