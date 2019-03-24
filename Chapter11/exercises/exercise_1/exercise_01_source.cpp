#include "exercise_01.h" 

void lowerFile(string input_file, string output_file)
{
    ifstream ist(input_file);
    ofstream ost(output_file);
    while (ist)
    {
        char character;
        ist >> character;
        character = tolower(character);
        ost << character;
    }
}