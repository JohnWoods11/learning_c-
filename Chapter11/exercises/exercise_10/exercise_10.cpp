#include "exercise_10.h"

void f()
{
    string s = "a series of whitespace seperated words";
    vector<string> substrings = split(s);
    for (auto substring : substrings)
    {
        cout << substring << endl;
    }
}


int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR\n";
        return -1;
    }
    return 0;
}