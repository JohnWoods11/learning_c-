#include "../../stdlibfacilities.h"

struct Reading
{
    char unit;
    int hour;
    double temperature;
};


ostream& operator<< (ostream &out, const Reading &r);

istream& operator>> (istream& in, Reading &r);

void tempStats(string filename);

void storeTemps(vector<Reading>&temps, string filename);

double medianTemp(const vector<Reading> &temps);                                 // should mean and median be here or hidden in the source file as
                                                                            // they are part of storeTemps()?
double meanTemp(const vector<Reading> &temps);

Reading& celsiusToFarenheit(Reading &r);

bool isValidReading(const Reading &r);