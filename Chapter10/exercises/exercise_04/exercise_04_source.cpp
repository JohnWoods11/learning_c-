#include "exercise_04.h"

/** output operator for a temperature reading*/
ostream& operator<< (ostream &out, const Reading &r)
{
    out << r.hour << "\t" << r.temperature << r.unit << endl;
    return out;
}

/** input operator for a temperture reading*/
istream& operator>> (istream &in, Reading &r)
{
    int hour;
    double temperature;
    char unit;
    in >> hour >> temperature >> unit;
    r.hour = hour;
    r.temperature = temperature;
    r.unit = unit;
    return in;
}

/** runs statistical analysis on a set of temperature readings stored in a file*/
void tempStats(string filename)
{
    vector<Reading>temps;
    ifstream ist{filename};
    Reading r;
    while (ist >> r)
    {
        if (isValidReading(r))
        {
            if (r.unit == 'C')
            {
                r = celsiusToFarenheit(r);
            }
            temps.push_back(r);
        }
    }
    cout << "Mean temperature: " << meanTemp(temps) << "°F" << endl << "Median temperature: " << medianTemp(temps) << "°F" << endl;
     
}

/** stores a vector of temperatures in a designated file*/
void storeTemps(vector<Reading> &temps, string filename)
{
    ofstream ost{filename};
    for (auto temp:temps)
    {
        if (isValidReading(temp))
        {
            ost << temp;
        }
    }
}

/** calculates the mean temperature of a set of temperature readings*/
double meanTemp(const vector<Reading> &temps)
{
    double sum = 0;
    for (auto temp:temps)
    {
        sum += temp.temperature;
    }
    return sum / double(temps.size());
}

/* calculates the median temperature of a set of temperature readings*/
double medianTemp(const vector<Reading> &temps)
{
    vector<double> temperatures;
    for (auto temp:temps)
    {
        temperatures.push_back(temp.temperature);
    }
    sort(temperatures.begin(), temperatures.end());
    if (temperatures.size() % 2 == 1)
    {
        return temperatures[temperatures.size() / 2];
    }
    return (temperatures[temperatures.size()/2] + temperatures[temperatures.size() / 2 - 1]) / 2;
}

/* converts celsius temperature readings to farenheit temperature readings*/
Reading& celsiusToFarenheit(Reading &r)
{
    double farenheit = r.temperature * 9 / 5 + 32;
    r.temperature = farenheit;
    r.unit = 'F';
    return r;
}


/* checks if a temperature reading is valid*/
bool isValidReading(const Reading &r)
{
    try
    {
        if (r.hour < 0 or r.hour > 23)
        {
            throw out_of_range("hour outside of acceptable range (0 - 23).");
        }
        if (r.unit != 'F' and r.unit != 'C')
        {
            throw out_of_range("unrecognised temperature unit - not supported by this program.");
        }
        if (r.unit == 'F' and r.temperature < -459.67 or r.unit == 'C' and r.temperature < -273.15)
        {
            throw out_of_range("reading temperature below absolute zero.");
        }
    }
    catch (const out_of_range &er)
    {
        cout << "Out of range error: Reading: " << r.hour << "h " << r.temperature << "°" << r.unit << " rejected, " << er.what() << endl;
        return false;
    }
    return true;

}