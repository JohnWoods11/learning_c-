#include "../stdlibfacilities.h"
#include <map>

char check_input()
{
    char inp;
    cin >> inp;
    while (inp < '0' or inp > '9')
    {
        if (inp == '.')
            break;
        cout << "not accepted, try again" << endl;
        cin >> inp;
    }
    return inp;
}


void convert_input(vector <int> & conversion)
{
    cout << "Please enter the number you would like to break down (4 digits maximum)." << endl << "Finish input by entering a full stop '.'" <<
    endl;
    while (conversion.size() < 4)
    {
        char input = check_input();
        if (input == '.')
            if (conversion.size() == 0)
                cout << "You have entered 0 digits. Please enter some before terminating." << endl;
            else
            break;
        else
            conversion.push_back(input - '0');
    }
}

void output_conversion()
{
    vector <int> conversion;
    convert_input(conversion);
    
    map <int, string> dec_modifier;
    dec_modifier[1] = "one";
    dec_modifier[2] = "ten";
    dec_modifier[3] = "hundred";
    dec_modifier[4] = "thousand";

    for (auto value:conversion)
        cout << value;
    cout << " is ";

    bool started = false;

    for (int i = 0; i < conversion.size(); i++)
    {
        if ((not started) and (conversion[i] > 0)){ started = true; }

        if (started)
        {
            cout << conversion[i] << " " << dec_modifier[conversion.size()-i];
            if (conversion[i] != 1)
                cout << "s";
            if (i != conversion.size()-1)
                cout << " and ";
        }
    } 
    cout << "." << endl;
}

int main ()
{
    try
    {
        output_conversion();
    }
    catch (...)
    {
    cout << "MAJOR ERROR." << endl;
    return -1;
    }

    return 0;
}
