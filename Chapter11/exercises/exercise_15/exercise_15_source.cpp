#include "exercise_15.h"

void outputSci(const string &filename)
{
    ifstream ifst(filename);
    while (ifst)
    {
        int numbers_in_line = 0;
        while (ifst and numbers_in_line < 4)
        {
            double number;
            ifst >> number;
            cout << left << scientific << setprecision(8) << setw(20) << number;
            numbers_in_line += 1;
        }
        cout << endl;
    }
}