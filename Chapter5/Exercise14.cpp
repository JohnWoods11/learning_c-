#include "stdlibfacilities.h"
using namespace std;

int exit_check (string day, string val);
int check_day (string day, int &reject_counter);
void day_vals (vector <int> day);
void day_sum (vector <int> day);

int main ()
{
    int reject_counter = 0;
    string day;
    string val;
    vector <int> mon;
    vector <int> tue;
    vector <int> wed;
    vector <int> thur;
    vector <int> fri;
    vector <int> sat;
    vector <int> sun;
    while (cin >> day >> val)
    {
        if (exit_check(day, val) == 1)
        {
            break;
        }
        switch (check_day (day, reject_counter))
        {
        case 0:
        {
            cout << day << "is not a day or synonym for one. Please try again.";
            break;
        }
        case 1:
        {
            mon.push_back(stoi(val));
            break;
        }
        case 2:
        {
            tue.push_back(stoi(val));
            break;
        }
        case 3:
        {
            wed.push_back(stoi(val));
            break;
        }
        case 4:
        {
            thur.push_back(stoi(val));
            break;
        }
        case 5:
        {
            fri.push_back(stoi(val));
            break;
        }
        case 6:
        {
            sat.push_back(stoi(val));
            break;
        }
        case 7:
        {
            sun.push_back(stoi(val));
            break;
        }
        }
    }
    day_vals(mon);
    day_vals(tue);
    day_vals(wed);
    day_vals(thur);
    day_vals(fri);
    day_vals(sat);
    day_vals(sun);
    day_sum(mon);
    day_sum(tue);
    day_sum(wed);
    day_sum(thur);
    day_sum(fri);
    day_sum(sat);
    day_sum(sun);
}

/*checks if exit code has been entered*/
int exit_check (string day, string val);

/*checks if the input to day is a day or common synonym for one. Adds rejects to reject counter*/
int check_day (string day, int &reject_counter);

/*outputs values of each days vector*/
void day_vals (vector <int> day);

/*sums each days vector and outputs sum*/
void day_sum (vector <int> day);


