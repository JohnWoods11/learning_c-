#include "exercise_15.h"


void f()
{
    Money m(300, Currency::USD), p(500, Currency::USD);
    Money s(m);
    cout << m + s << endl;
    cout << p - m << endl;
    cout << p * 2 << endl;
    cout << p * 0.5 << endl;
    Money t;
    cin >> t;
    cout << t << endl;
    m = m - t;
}

int main()
{
    try
    {
        f();
    }
    catch(const exception &err)
    {
        cout << "MAJOR ERROR: " << err.what() << endl;
        return -1;
    }
    return 0;    
}