#include "exercise_03.h"

ostream& operator<< (ostream &out, const Reading &r)
{
    out << r.hour << "\t" << r.temperature << endl;
    return out;
}

istream& operator>> (istream &in, Reading &r)
{
    int hour;
    double temperature;
    in >> hour >> temperature;
    r.hour = hour;
    r.temperature = temperature;
    return in;
}

void tempStats(string filename)
{
    vector<Reading>temps;
    ifstream ist{filename};
    Reading r;
    while (ist >> r)
    {
        temps.push_back(r);
    }
    cout << meanTemp(temps) << endl << medianTemp(temps) << endl;
     
}

void storeTemps(vector<Reading> &temps, string filename)
{
    ofstream ost{filename};
    for (auto temp:temps)
    {
        ost << temp;
    }
}


double meanTemp(vector<Reading> &temps)
{
    double sum = 0;
    for (auto temp:temps)
    {
        sum += temp.temperature;
    }
    return sum / double(temps.size());
}

double medianTemp(vector<Reading> &temps)
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