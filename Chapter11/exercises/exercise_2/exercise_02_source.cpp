#include "exercise_02.h"

bool lineContains(string, string);

/** Prints the line number and lines containing a specified series of characters in a specified file*/
void linesContaining(string filename, string text)
{
    ifstream ist(filename);
    int line_number = 0;
    while (ist)
    {
        line_number += 1;
        string line;
        getline(ist, line);
        if (lineContains(line, text))
        {
            cout << "line nuber " << line_number << "\t" + line + "\n";
        }
    }
    cout << "End of file reached,\n";
}

/** Returns true if a specified string contains a specified series of characters*/
bool lineContains(string line, string text)
{
    stringstream ss(line);
    for (string s; ss >> s; )
    {
        if (s == text)
        {
            return true;
        }
    }
    return false;
}