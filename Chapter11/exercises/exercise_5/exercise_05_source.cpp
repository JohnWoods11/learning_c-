#include "exercise_05.h"

/** Outputs to the terminal all the classifications of each character in a string*/
void classifyChars(const string &text)
{
    for (auto character : text)
    {
        cout << "Character '" << character << "' is:\n";
        if (isspace(character))
        {
            cout << "A space\n";
        }
        if (isalpha(character))
        {
            cout << "A letter\n";
        }
        if (isdigit(character))
        {
            cout << "A numeral\n";
        }
        if (isxdigit(character))
        {
            cout << "A hexadecimal digit\n";
        }
        if (isupper(character))
        {
            cout << "A upper case character\n";
        }
        if (islower(character))
        {
            cout << "A lower case character\n";
        }
        if (isalnum(character))
        {
            cout << "A alphanumeric character\n";
        }
        if (iscntrl(character))
        {
            cout << "A control character\n";
        }
        if (ispunct(character))
        {
            cout << "A punctuation character\n";
        }
        if (isprint(character))
        {
            cout << "A printable character\n";
        }
        if (isgraph(character))
        {
            cout << "Not a space character\n";
        }
    cout << "-----------------------\n";    
    }
} 