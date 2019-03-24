#include "exercise_06.h"

void f()
{
    Roman_int a("IV");
    Roman_int b("XIV");
    Roman_int c("XXX");
    Roman_int d("VX");
    cout << a << endl << a.asInt() << endl;
    cout << b << endl << b.asInt() << endl;
    cout << c << endl << c.asInt() << endl;
    cout << d << endl << d.asInt() << endl;
}

int main()
{
    try 
    {
        f();
    }
    catch (const exception &err)
    {
        cout << "Major Error." << err.what() << endl;
    }
}