#include "../stdlibfacilities.h"



string get_part()
{
    string part;
    cin >> part;

    if (part == "birds" or part == "fish" or part == "C++")
        return "noun";
    else if (part == "rules" or part == "fly" or part == "swim")
        return "verb";
    else if (part == "and" or part == "or" or part == "but")
        return "conjunction";
    else if (part == ".")
        return ".";
    else
        return "invalid";
}

string part()
{
    string left = get_part();

    if (left == "noun")
    {
        if (get_part() == "verb")
        return "sentence";
    } 
    else
    return left;
}

string sentence()
{
    string left = part();

    while (true)
    {
        string next = part();

        if (left == "sentence")
        {
            if (next == "conjunction")
            {
                if (part() == "sentence")
                {
                    left = "sentence";
                }
                else 
                {
                    left = "invalid";
                }
            }
            else if (next == ".")
            {
                return left;
            }
            else
            {
                left = "invalid";
            }
        }
        if (next == ".")
        {
            return left;
        }
    }
}

void grammar_check()
{
if (sentence() == "sentence")
{
    cout << "OK." << endl;
}
else
{
    cout << "not OK." << endl;
}
}


int main()
{
    cout << "Please enter the string that you would like to check against the grammar." << endl
    << "Terminate string with ' .' (a whitespace followed by a full stop)." << endl;
    while (true)
    {
     grammar_check();
    }
}