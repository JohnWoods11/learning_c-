#include "exercise_09.h"

void mergeSortedFiles(string file_one, string file_two)
{
    ifstream first_file{file_one};
    ifstream second_file{file_two};
    ofstream ost{"new_file.txt"};
    string first_word = "EMPTY";
    string second_word = "EMPTY";


    while (first_file.good() and second_file.good())
    {
        if (first_word == "EMPTY")
        {
            first_file >> first_word;
        }
        if (second_word == "EMPTY")
        {
            second_file >> second_word;
        }
        if (first_word < second_word)
        {
            ost << first_word << " ";
            first_word = "EMPTY";
        }
        else if (second_word < first_word)
        {
            ost << second_word << " ";
            second_word = "EMPTY";
        }
    }

    if (first_file.good() and second_file.eof())
    {
        while (true)
        {
            ost << first_word << " ";
            if (!(first_file >> first_word))
            {
                break;
            }
        }
    }

    if (first_file.eof() and second_file.good())
    {
        while (true)
        {
            ost << second_word << " ";
            if (!(second_file >> second_word))
            {
                break;
            }
        }
    }
}