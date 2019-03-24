#include "drill_01.h"

void f()
{
    Point p(2, 3);
    Point c;
    Point d(p);
    c = d;
    cout << d.y() << c.y() << p.y();
}

int main()
{
    try
    {
        f();
    }
    catch(...)
    {
        cout << "unforseen error." << endl;
    }
    
}