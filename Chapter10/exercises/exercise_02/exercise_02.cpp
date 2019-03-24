#include "exercise_02.h"

void f()
{
    vector<Reading> temps;
    for (int i = 0; i < 50; i++)
    {
        Reading r;
        r.hour = i % 24;
        r.temperature = rand() % 10;
        temps.push_back(r);
    }
    storeTemps(temps, "raw_temps.txt");
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