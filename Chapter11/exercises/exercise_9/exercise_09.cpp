#include "exercise_09.h"

void f()
{
    string filename = "file.txt";
    textToBinary(filename);
    binaryToText(filename);
}


int main()
{
    try
    {
        f();
    }
    catch (const invalid_argument &err)
    {
        cout << "ERROR: " << err.what() << "\n";
    }
    catch (...)
    {
        cout << "MAJOR ERROR\n";
        return -1;
    }
    return 0;
}