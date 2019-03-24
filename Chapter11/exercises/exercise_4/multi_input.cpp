#include "exercise_04.h"

int convertToDec(const string &integer, string &type);


void multiInput()
{
    cout << "Please enter several integers in hexadecimal, octal or decimal:\n";
    while (cin)
    {
        string input;
        string type;
        cin >> input;
        int integer = convertToDec(input, type);
        cout << setw(10) << input << setw(14) << type << " converts to " << setw(10) << integer << " decimal\n";
    }    
}

int convertToDec(const string &integer, string &type)
{
    int dec_number;
    stringstream ss(integer);
    if (integer[0] == '0')
    {
        if (integer[1] == 'x')
        {
            if (!(ss >> hex >> dec_number) or !ss.eof())
            {
                throw invalid_argument(integer + " not a valid hexadecimal");
            }
            type = "hexadecimal";
        }
        else if (integer[1] >= 1 or integer[1] <= 9)
        {
            if (!(ss >> oct >> dec_number) or !ss.eof())
            {
                throw invalid_argument(integer + " not a valid octal");
            }
            type = "octal";
        }
    }
    else 
    {
        if (!(ss >> dec_number) or !ss.eof())
        {
            throw invalid_argument(integer + " not a valid decimal");
        }
        type = "decimal";
    }
    return dec_number;
}