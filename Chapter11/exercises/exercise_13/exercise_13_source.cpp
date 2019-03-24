#include "exercise_13.h"



void reverseWords(string &text);


/** Reverses the order of words in a text file*/
void reverseFileWords(string &filename)
{
    ifstream ifst(filename);
    if (!ifst)
    {
        throw invalid_argument("could not open file " + filename);
    }
    string file_text;
    for (char character; ifst.get(character); )
    {
        file_text += character;
    }

    reverseWords(file_text);
    
    ofstream ofst(filename);
    ofst << file_text;
}


void reverseWords(string &text)
{
    vector<string> words;
    stringstream ss(text);
    for (string word; ss >> word; )
    {
        words.push_back(word);
    }
    string reversed_words;
    for (int i = words.size()-1; i >=0; i--)
    {
        reversed_words += words[i];
        if (i != 0)
        {
            reversed_words += ' ';
        }
    }
    text = reversed_words;
}