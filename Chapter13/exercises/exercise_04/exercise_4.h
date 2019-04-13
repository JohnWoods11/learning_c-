#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"
#include "../GUI/std_lib_facilities.h"
#include <iostream>

Point* n(const Rectangle &rect)
{
    Point *p = new Point(rect.point(0).x + rect.width() / 2, rect.point(0).y);
    return p;
}

Point* e(const Rectangle &rect)
{
    Point *p = new Point(rect.point(0).x + rect.width(), rect.point(0).y + rect.height() / 2);
    return p;
}

Point* s(const Rectangle & rect)
{
    Point *p = new Point(rect.point(0).x + rect.width() / 2, rect.point(0).y + rect.height());
    return p;
}

Point* w(const Rectangle & rect)
{
    Point *p = new Point(rect.point(0).x, rect.point(0).y + rect.height() / 2);
    return p;
}

Point* center(const Rectangle & rect)
{
    Point *p = new Point(rect.point(0).x + rect.width() / 2, rect.point(0).y + rect.height() /2);
    return p;
}

Point* ne(const Rectangle & rect)
{
    Point *p = new Point(rect.point(0).x + rect.width(), rect.point(0).y);
    return p;
}

Point* se(const Rectangle & rect)
{
    Point *p = new Point(rect.point(0).x + rect.width(), rect.point(0).y + rect.height());
    return p;
}

Point* sw(const Rectangle & rect)
{
    Point *p = new Point(rect.point(0).x, rect.point(0).y + rect.height());
    return p;
}

Point* nw(const Rectangle & rect)
{
    Point *p = new Point(rect.point(0).x, rect.point(0).y);
    return p;
}
