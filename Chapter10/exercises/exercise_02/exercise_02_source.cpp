#include "exercise_02.h"

ostream& operator<< (ostream &out, Reading &r)
{
    out << r.hour << "\t" << r.temperature << endl;
    return out;
}

void storeTemps(vector<Reading> temps, string filename)
{
    ofstream ost{filename};
    for (auto temp:temps)
    {
        ost << temp;
    }
}