#include "exercise_11.h"

int sumFileNum(string name)
{
    ifstream ist{name};
    int sum = 0;
    while (ist.good())
    {
        string text;
        ist >> text;
        if (stringIsInt(text))
        {
            sum += stoi(text);
        }
    }
    return sum;    
}

/** Return integer, or 0 if not integer */
int stringToInt(const string &text)
{
    for (const auto &character : text)
    {
        if (not isdigit(character))
        {
            return 0;
        }
    }

    return stoi(text);
}

int sumFileNum(string name)
{
    ifstream ist{name};
    int sum = 0;
    while (ist.good())
    {
        string text;
        ist >> text;
        sum += stringToInt(text):
    }
    return sum;    
}

O(1)
O(log n)
O(n) = doubles, so cost doubles
O(n log n) = doubles, so cost triples
O(n^2) = doubles, so cost quadruples
O(n^3) = doubles, so cost octuples

for (int i=0; i<m; ++i){ for (int j=0; j<n; ++j){ }}

bool stringIsInt(string text)
{
    for (auto character:text)
    {
        if (not isdigit(character))
        {
            return false;
        }
    }
    return true;
}