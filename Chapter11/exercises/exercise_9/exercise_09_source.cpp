#include "exercise_09.h"

void textToBinary(const string &filename)
{
    string file_contents;
    ifstream ifst(filename);
    if (!ifst)
    {
        throw invalid_argument("can't open the file for conversion.");
    }
    for (char character ; ifst.get(character) ; )
    {
        file_contents += character;
    }
    ofstream ofst_binary(filename, ios_base::binary);
    for (auto character : file_contents)
    {
        ofst_binary.write(as_bytes(character),sizeof(char));
    }
}


void binaryToText(const string &filename)
{
    string file_contents;
    ifstream ifst_binary(filename, ios_base::binary);
    if (!ifst_binary)
    {
        throw invalid_argument("can't open the file for conversion.");
    }
    for (char character; ifst_binary.read(as_bytes(character), sizeof(char)); )
    {
        file_contents += character;
    }
    ofstream ofst(filename);
    ofst << file_contents;
}