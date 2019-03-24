#include "exercise_04.h"

void f()
{
    vector<Reading> temps;
    for (int i = 0; i < 48; i++)
    {
        Reading r;
        r.hour = i % 24;
        r.temperature = 1;
        r.unit = 'C';
        temps.push_back(r);
    }
    storeTemps(temps, "raw_temps.txt");                 //why do i get compiler error if i try pass string by reference?
    tempStats("raw_temps.txt");                         //is the way i did median in this function the best way?
}           

int main ()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR." << endl;
    }
}