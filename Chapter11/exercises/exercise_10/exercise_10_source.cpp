#include "exercise_10.h"


vector<string> split(const string &s)
{
    vector<string> substrings;
    stringstream ss(s);
    for (string substring ; ss >> substring ; )
    {
        substrings.push_back(substring);
    }
    return substrings;
}