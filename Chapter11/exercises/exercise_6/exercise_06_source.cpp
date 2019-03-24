#include "exercise_06.h"

/** Replaces . ; , ? - ' punctuation characters with whitespace unless they occur within a set of double quotes*/
void removePunctuation(const string &text)
{
    stringstream ss(text);
    string new_text;
    bool in_quote = false;
    for (char character; ss.get(character) ; )
    {
        if (character == '"' and in_quote == false)
        {
            in_quote = true;
        }
        else if (character == '"' and in_quote == true)
        {
            in_quote = false;
        }
        if (in_quote == false)
        {
            switch (character)
            {
                case '.': case ';': case ',': case '?': case '-': case '\'':
                {
                    new_text += ' ';
                    break;
                } 
                default:
                {
                    new_text += character;
                }
            }
        }
        else 
        {
            new_text += character;
        }
    }
    cout << new_text << "\n";
}

