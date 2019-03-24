#include "../../stdlibfacilities.h"

struct Reading
{
    int hour;
    double temperature;
};

ostream& operator<< (ostream &out, const Reading &r);

istream& operator>> (istream& in, Reading &r);

void tempStats(string filename);

void storeTemps(vector<Reading>&temps, string filename);

double medianTemp(vector<Reading> &temps);

double meanTemp(vector<Reading> &temps);