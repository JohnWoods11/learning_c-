#include "exercise_07.h"

void changeWord(string &text, const string &, const string &);

/** Replaces . ; , ? - ' punctuation characters with whitespace unless they occur within a set of double quotes*/
void removePunctuation(string text)
{
    changeWord(text, "don't", "do not");
    changeWord(text, "can't", "cannot");
    stringstream ss(text);
    string new_text;
    bool in_quote = false;
    char previous_character;
    for (char character; ss.get(character) ; previous_character = character)
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
                case '.': case ';': case ',': case '?': case '\'':
                {
                    new_text += ' ';
                    break;
                } 
                case '-':
                {
                    char next_character;
                    ss.get(next_character);
                    if (isalpha(previous_character) and isalpha(next_character))
                    {
                        new_text += '-';
                    }
                    else
                    {
                        new_text += ' ';
                    }
                    ss.putback(next_character);
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


/** Replaces don't with do not and can't with cannot*/
void changeWord (string &text, const string &old_word, const string &new_word)
{
    stringstream ss(text);
    string new_text;
    for (char next_character ; ss.get(next_character) ; )
    {
        if (!isspace(next_character))
        {
            ss.putback(next_character);
            string next_string;
            ss >> next_string;
            if (next_string == old_word)
            {
                next_string = new_word;
            }
            new_text += next_string;
        }
        else
        {
            new_text += next_character;
        }
    }
    text = new_text;
}