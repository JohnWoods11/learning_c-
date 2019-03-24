#include "exercise_03.h"
bool isVowel(const char character);

/** Removes all vowels from a target file*/
void disemvowel(const string &filename)
{
    string new_file_contents;
    ifstream ist(filename);
    while (ist)
    {
        char character;
        ist.get(character);
        if (!isVowel(character))
        {
            new_file_contents += character;
        }
    }
    ofstream ost(filename);
    ost << new_file_contents;
}

/** Returns true of the character is a vowel*/
bool isVowel(char character)
{
    char lower_character = tolower(character);
    switch (lower_character)
    {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        {
            return true;
        }
        default:
        {
            return false;
        }
    }
}