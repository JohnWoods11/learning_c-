#include "../stdlibfacilities.h"
#include <iomanip>

void f()
{
    cout << setw(10) << "John" << setw(15) << "Woods" << setw(20) << "07862321324" << setw(25) << "random@gmail.com\n"
    << setw(10) << "Daniel" << setw(15) << "Stafford" << setw(20) << "07863546334" << setw(25) << "random@gmail.com\n"
    << setw(10) << "Kieran" << setw(15) << "Gallagher" << setw(20) << "07863243244" << setw(25) << "random@gmail.com\n"
    << setw(10) << "Jordan" << setw(15) << "Reeve" << setw(20) << "07862343244" << setw(25) << "random@gmail.com\n"
    << setw(10) << "Paul" << setw(15) << "Laws" << setw(20) << "07862342344" << setw(25) << "random@gmail.com\n";
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