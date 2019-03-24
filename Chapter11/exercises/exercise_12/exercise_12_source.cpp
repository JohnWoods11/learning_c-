#include "exercise_12.h"



void reverseText(string &text);


/** Reverses the order of characters in a text file*/
void reverseFileText(string &filename)
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

    reverseText(file_text);
    
    ofstream ofst(filename);
    ofst << file_text;
}


void reverseText(string &text)
{
    string reversed_string;
    for (int i = text.size()-1 ; i >= 0 ; i--)
    {
        reversed_string += text[i];
    }
    text = reversed_string;
}