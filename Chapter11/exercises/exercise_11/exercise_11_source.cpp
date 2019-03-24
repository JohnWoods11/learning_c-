#include "exercise_11.h"

string whitespaceChars(const string &s, const string &whitespace_chars);

/** Returns a vector of whitespace seperated substrings where the chars in whitespace_chars are treated as whitespace*/
vector<string> split(const string &s, const string &whitespace_chars)
{
    vector<string> substrings;
    string text = whitespaceChars(s, whitespace_chars);
    stringstream ss(text);
    for (string substring ; ss >> substring ;)
    {
        substrings.push_back(substring);
    }
    return substrings;
}


/** Returns a sourced string with specified characters replaced with whitespace*/
string whitespaceChars(const string &s, const string &whitespace_chars)
{
    stringstream ss(s);
    string new_string;
    for (char string_char ; ss.get(string_char) ;)
    {
        bool is_whitespace_char = false;
        for (auto whitespace_char : whitespace_chars)
        {
            if (string_char == whitespace_char)
            {
                is_whitespace_char = true;
                break;
            }
        }
        if (is_whitespace_char == true)
        {
            new_string += ' ';
        }
        else 
        {
            new_string += string_char;
        }
    }
    return new_string;
}