#include "../stdlibfacilities.h"

void f()
{
    int a;
    int b;
    int c;
    int d;
    cin.unsetf(ios::dec);
    cin.unsetf(ios::oct);
    cin.unsetf(ios::hex);
    cin >> a  >> b  >> c >> d;
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\n";
}

int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "Major Error!";
    }
}