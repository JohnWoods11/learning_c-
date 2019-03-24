#include "../stdlibfacilities.h"
#include <iomanip>

void f()
{
    cout << defaultfloat << setprecision(5) << 1234567.89 << "\t\t(defaultfloat)\n" << fixed << 1234567.89 << "\t(fixed)\n" << scientific 
    << 1234567.89 << "\t(scientific)\n" << setw(8) << 123456 << "."; 
}


int main()
{
    try
    {
        f();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    return 0;    
}