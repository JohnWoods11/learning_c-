#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int exit_check (string day, string val);
int check_day (string day, int &reject_counter);
void day_vals (vector <int> day, string name);
void day_sum (vector <int> day, string name);

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
    cout << "Please enter 'day of the week/value' pairs (e.g. monday 12). Once all pairs are entered please enter 'Exit' to end input.";
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
            cout << day << " is not a day or synonym for one. Please try again.";
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
    day_vals(mon, "Monday");
    day_vals(tue, "Tuesday");
    day_vals(wed, "Wednesday");
    day_vals(thur, "Thursday");
    day_vals(fri, "Friday");
    day_vals(sat, "Saturday");
    day_vals(sun, "Sunday");
    day_sum(mon, "mondays");
    day_sum(tue, "tuesdays");
    day_sum(wed, "wednesdays");
    day_sum(thur, "thursdays");
    day_sum(fri, "fridays");
    day_sum(sat, "saturdays");
    day_sum(sun, "sundays");
    cout << endl << "There were " << reject_counter << " day/value pairs rejected.";
}

/*checks if exit code has been entered*/
int exit_check (string day, string val)
{
    if (day == "Exit" || day == "exit" || day == "EXIT" || val == "Exit" || val == "exit" || val == "EXIT")
    {
        cout << "Exiting..";
        return 1;
    }
    else
        return 0;
}

/*checks if the input to day is a day or common synonym for one. Adds rejects to reject counter*/
int check_day (string day, int &reject_counter)
{
    if (day == "monday" || day == "Monday"|| day == "MONDAY" || day == "mon" || day == "Mon" || day == "MON")
    return 1;
    else if (day == "tuesday" || day == "Tuesday"|| day == "TUESDAY" || day == "tue" || day == "Tue" || day == "TUE")
    return 2;
    else if (day == "wednesday" || day == "Wednesday"|| day == "WEDNESDAY" || day == "wed" || day == "Wed" || day == "WED")
    return 3;
    else if (day == "thursday" || day == "Thursday"|| day == "THURSDAY" || day == "thur" || day == "Thur" || day == "THUR")
    return 4;
    else if (day == "friday" || day == "Friday"|| day == "FRIDAY" || day == "fri" || day == "Fri" || day == "FRI")
    return 5;
    else if (day == "saturday" || day == "Saturday"|| day == "SATURDAY" || day == "sat" || day == "Sat" || day == "SAT")
    return 6;
    else if (day == "sunday" || day == "Sunday"|| day == "SUNDAY" || day == "sun" || day == "Sun" || day == "SUN")
    return 7;
    else 
    reject_counter ++;
    return 0;
}

/*outputs values of each days vector*/
void day_vals (vector <int> day, string name)
{
    cout << endl << name;
    for (int i = 0; i < day.size(); i++)
    {
        cout << " " << day[i];
    }
}

/*sums each days vector and outputs sum*/
void day_sum (vector <int> day, string name)
{
    int sum = 0;
    for (int i = 0; i < day.size(); i++)
    {
        sum += day[i];
    }
    cout << endl << "The sum of " << name << " values is " << sum;
}

/*questions:

When i used a range for loop for day_sum and day_vals it seemed to iterate over 3 members at a time
the loop i used looked like 'for (int i: days)'. why?

Other than using to_lower which seemed outside the scope of this exercise is there an easier way to check
against several options than the way i did in check_day and exit_check?

Is there a way to access the name of a vector using cout. or must i also pass it as i did in check_day and 
exit_check?

When i called the day_vals and day_sums functions would it have been better practice to use a vector of the days
and a for loop to call them? i.e.

vector <string> days_names (mon - sun);
vector <string> days_names_full (monday - sunday);

for (int i = 0; i < days_names.size(); i++)
{
    day_vals(day_names[i], day_names_full[i]);
    day_sum(day_names[i], day_names_full[i]);
}
*/


