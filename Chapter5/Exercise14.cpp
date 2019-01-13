#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool exit_check (string day, string val);
int check_day (string day, int &reject_counter);
int mainfunc();

void day_vals (vector <int> day, string name);


void day_sum (vector <int> day, string name);

string lowercase(string input)
{
    std::locale loc;
    for (int i=0; i<input.length(); ++i)
    {
        input[i] = std::tolower(input[i], loc);
    }
    return input;
}

int main ()
{
    try
    {
        return mainfunc();
    }
    catch(const exception &err)
    {
        cout << "MAJOR ERROR: " << err.what() << endl;
        return -1;
    }
    catch(...)
    {
        cout << "MAJOR UNRECOGNISED ERROR\n";
        return -1;
    }

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
bool exit_check (string day, string val)
{
    if (lowercase(day) == "exit" or lowercase(day) == "quit")
    {
        cout << "Exiting..";
        return true;
    }
    else
        return false;
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

/*outputs values of each days vector

   name = "Monday"
   day = { 1, 5, 6, 7, 10, 12 }

   vector<float> widths = { 1.5, 2.0, 6.2 };

   for (auto width : widths)
   {
       cout << width << " ";
   }

*/
void day_vals (vector<int> values, string name)
{
    cout << endl << name;
    for (auto value : values)
    {
        cout << " " << value;
    }
}

/*sums each days vector and outputs sum*/
void day_sum (vector <int> values, string name)
{
    int sum = 0;
    for (auto value: values)
    {
        sum += value;
    }
    cout << endl << "The sum of " << name << " values is " << sum;
}


int mainfunc()
{
    vector< vector<int> > days;
    vector<string> day_names;

    for (int i=0; i<7; ++i)
    {
        days.push_back( vector<int>() );
    }

    day_names.push_back("Monday");
    day_names.push_back("Tuesday");
    day_names.push_back("Wednesday");
    day_names.push_back("Thursday");
    day_names.push_back("Friday");
    day_names.push_back("Saturday");
    day_names.push_back("Sunday");

    map<string,int> day_tokens;

    for (int i=0; i<day_names.size(); ++i)
    {
        day_tokens[ lowercase(day_names[i]) ] = i;
    }

    day_tokens["mon"] = 0;
    day_tokens["tue"] = 1;

    int reject_count = 0;

    string input1, input2;

    cout << "Create some input:\n";

    while (true)
    {
        cin >> input1;

        if (exit_check(input1, input1))
        {
            break;
        }

        cin >> input2;

        if (exit_check(input2, input2))
        {
            break;
        }

        try
        {
            int day = day_tokens.at(lowercase(input1));

            int date = stoi(input2);

            if (date < 1 or date > 31)
            {
                throw invalid_argument(input2 + " is not between 1 and 31");
            }

            days[day].push_back(date);
        }
        catch(out_of_range e)
        {
            cout << "Invalid input: " << e.what() << " " << input1 << endl;
            reject_count += 1;
        }
        catch(invalid_argument e)
        {
            cout << "Invalid input: " << e.what() << " " << input2 << endl;
            reject_count += 1;
        }
    }

    for (int i=0; i<7; ++i)
    {
        day_vals(days[i], day_names[i]);
        day_sum(days[i], day_names[i]);
    }

    cout << endl << "Reject count equals " << reject_count << endl;

    return 0;
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


