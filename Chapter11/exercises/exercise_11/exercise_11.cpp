#include "exercise_11.h"


void f()
{
    string s = "a series of whitespace seperated words";
    string w = "ae";
    vector<string> substrings = split(s, w);
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