#include "exercise_08.h"


/** Makes all uppercase characters lowercase*/
void toLowerString(string &text)
{
    stringstream ss(text);
    string new_text;
    for (char character ; ss.get(character) ; )
    {
        new_text += tolower(character);
    }
    text = new_text;
}

/** Replaces non words with whitespace characters with whitespace*/
void removeNonWords(string &text)
{
    stringstream ss(text);
    string new_text;
    char previous_character;
    for (char character; ss.get(character) ; previous_character = character)
    {
        
        if (!isalpha(character) and character != '-')
        {
            new_text += ' ';
        } 
        else if (character == '-')
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
        }
        else
        {
            new_text += character;
        }
    }        
    text = new_text;
}


/** Replaces ecery instance of a word in a text with a specified word*/
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

/** Takes text and creates a dictionary of whitespace seperated words that occurs in the text (removes punctuation)*/
string makeDictionary(const string &text)
{
    string text_copy = text;
    removeNonWords(text_copy);
    stringstream dictionary_source(text_copy);
    string dictionary;
    vector<string> unique_words;
    for (string word ; dictionary_source >> word ; )
    {
        bool unique = true;
        for (auto unique_word : unique_words)
        {
            if (word == unique_word)
            {
                unique = false;
                break;
            }
        }
        if (unique == true)
        {
            unique_words.push_back(word);
        }
    }
    sort(unique_words.begin(), unique_words.end());
    for (auto word : unique_words)
    {
        dictionary += (word + "\n");
    }
    return dictionary;
}