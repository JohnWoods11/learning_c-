#include "../../stdlibfacilities.h"

struct Reading
{
    int hour;
    double temperature;
};

ostream& operator<< (ostream &out, Reading &r);

void storeTemps(vector<Reading>temps, string filename);