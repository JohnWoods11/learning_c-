#include "exercise_13.h"

void f()
{
    Rational t(5,5);
    Rational p(3,2);
    Rational a = t + p;
    cout << t + p << endl;
    cout << t - p << endl;
    cout << t / p << endl;
    cout << t * p << endl;
    cout << t << endl;
    cout << p << endl;
    t = p;
    cout << t << endl;
    cout << t.convertToDouble() << endl;
    if (t != p)
    {
        cout << "false";  
    }
    else 
    {
        cout << "true";
    }
    
}


int main()
{
    try
    {
        f();
    }
    catch(...)
    {
        cout << "MAJOR ERROR";
        return -1;
    }
    return 0;    
}