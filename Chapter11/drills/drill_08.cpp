#include "../stdlibfacilities.h"

void f()
{
    int a, b, c, d;

    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}


int main()
{
    try
    {
        f();
    }    
    catch (...) 
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}

// When entering 1234 for integers a, b, c and d:
// the resulting numbers are all 1234 however only the first is shown in the default dec base, the base is changed to oct for the second number
// then to hex for the third number. The base is not changed for the fourth number so remains as hex as the bases are sticky and therefore 
// the third and fourth numbers are bothrepresented in hex base. 