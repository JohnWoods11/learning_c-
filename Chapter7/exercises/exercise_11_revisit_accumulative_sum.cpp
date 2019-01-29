/*
Old chapter 5 exercise 10:

Original #include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main ()
{
cout << "Please enter the number of values you would like to sum:"<<endl;
int n;
cin >> n;
cout << "Please enter some integers (press '|' to stop):"<<endl;
vector <double> entries;
int entry;
while (cin >> entry) entries.push_back(entry);
if (entries.size() < n)
{
    cout << "Error you asked for a sum of more numbers than you entered"<<endl;
    return 1;
}
else
{
    cout << "The sum of the first " << n << " numbers ( ";
    double sum = 0;
    vector <double> difference;
    for (int i = 0; i < n; i++)
    {
        sum += entries[i];
        cout << entries[i] << " ";
        if (i > 0)
        {
            difference.push_back(entries[i] - entries[i - 1]);
        }
    }
    cout << ") is " << sum << "." << endl;
    cout << "The difference the " << n << " integers are as follows:";
    for (int i = 0; i < difference.size(); i++)
    cout << " " << difference[i];
    cout << "." << endl;
}
}

*/

/*

This program first stores a series of doubles and then computes the sum of the fist 'N' doubles. Where 'N' is specidfied by user input.
This particular version is an improvement on the program written for Chapter 5 Exercise 10 in Bjarne Stroustrups 'Programing principles 
and practice using C++'.

Revised by John Woods January 2019
Written by John Woods January 2019

Analysis

The program needs to be able to store a series of doubles of unknown size provided by the user. Then once the user indicates they have finished
entry it needs to prompt the user for how many of the doubles they would like to sum (N). Then it needs to sum the first 'N' doubles and return
the result to the user.
________________________________________


Design

Check input:
ensure the series and is made up of doubles

Store doubles:
check input()
take user input and store it in a vector
terminate entry

Sum doubles:
sum first 'N' values of series

Print sum doubles
print sum

Get n
set n

Try another calculation
ask if user wants to do another calculation
act accordingly

User interface:
print instructions
ask for series
store doubles()
ask for n
get n()
print sum doubles()
try another ccalculation()

main 
start
catch errors
terminate

encapsulate above into class
*/

#include "../stdlibfacilities.h"

/** Handles functionality for number collection and multiple summations of from series begining to user specified end point.*/
class accumulator
{

public:
    void print_instructions();
    void store_doubles();
    void print_sum_doubles();
    bool should_try_again();
 
private:
    void sum_doubles();
    void get_number_of_doubles_to_sum();
    void check_series_input();
    string check_yes_no_input();
    double sum_of_first_n_doubles;
    int number_of_doubles_to_sum;
    vector<double> series;
    bool new_series = true;                                                             
    bool input_termination = false;
};

/**Print the instructions for use of the accumulator*/
void accumulator::print_instructions()
{
    cout << "First enter a series of values. (they can be integers or floating-point values)" << endl <<
    "Once you have enterred all you values enter a 'q' to terminate input" << endl << "Then enter the number of values you would like to sum" <<
    endl << "The program will sum the first N values. (N being the number you input)" << endl << endl;
}

/**Parse user input into the answer to a yes or no question*/
string accumulator::check_yes_no_input()
{
    string str;
    while (true)
    {
        try
        {
            cin >> str;
            if (str != "y" and str != "n")
                {
                    throw invalid_argument("The command '" + str + "' is unrecognised. Please enter a 'y' (yes) or a 'n' (no).");
                }
            return str;
        }
        catch (const invalid_argument& err)
        {
            cout << "Error: " << err.what() << endl;
        }
     }
}

/**Ask the user if they would like to continue using the accumulator*/
bool accumulator::should_try_again()
{
    cout << "Would you like to try another calculation with the same series? (y/n)" << endl;
    if (check_yes_no_input() == "y")
    {
        new_series = false;
        return true;
    }
    cout << endl << "Would you like to try another calculation with a new series? (y/n)" << endl;
    if (check_yes_no_input() == "y") 
    {
        new_series = true;
        series.clear();
        return true;
    }
    return false;
}

/**Print the sum of the values the user requested*/
void accumulator::print_sum_doubles()
{
    get_number_of_doubles_to_sum();
    sum_doubles();
    if (number_of_doubles_to_sum != 1)
    {
        cout << "The sum of the first " << number_of_doubles_to_sum << " numbers in your series is " << sum_of_first_n_doubles << "." << endl
         << endl;
    }
    else
    {
        cout << "The first number in your series is " << sum_of_first_n_doubles << "." << endl << endl;
    }
    
}

/**Calculate the sum of the values the user requested*/
void accumulator::sum_doubles()
{
    sum_of_first_n_doubles = 0;
    for (int i = 0; i < number_of_doubles_to_sum; i++)
    {
        sum_of_first_n_doubles += series[i];
    }
}

/**Ask the user which values they want summed*/
void accumulator::get_number_of_doubles_to_sum()
{
    cout << endl << "Number of values in your series you would like to sum: ";
    while(true)
    {
        try
        {
            string str;
            cin >> str;
            int i;
            try
            {
                i = stoi(str);
            }
            catch (const invalid_argument& err)
            {
                throw invalid_argument("'" + str + "' is not an integer.");
            }
            if (i < 1)
            {
                throw invalid_argument("The number of values to sum can not be less than 1.");
            }
            if (i > series.size())
            {
                throw invalid_argument("The number of values to sum can not be larger than the number of values you entered.");
            } 
            number_of_doubles_to_sum = i;
            return; 
        }
        catch (const invalid_argument& err)
        {
            cout << "Error: " << err.what() << endl;
        }
    }
}

/**Store the doubles entered by the user*/
void accumulator::store_doubles()
{
    if (new_series == false)
        return;
    input_termination = false;
    cout << "Series:" << endl;
    while (input_termination == false)
    {
        check_series_input();
    }
}

/**Manage series input and terminate on cue*/
void accumulator::check_series_input()
{
    while (true)
    {
        string str;
        cin >> str;
        try
        {
            if (str == "q")
            {
                input_termination = true;
                return;                                                        
            }                                                                      
            else
            {
                try                                                                 
                {
                    series.push_back(stod(str));   
                    return;                                              
                }                                                                  
                catch (const invalid_argument& err)
                {
                    throw invalid_argument("'" + str + "' is neither a floating-point number or the termination character (q).");
                }
            }
        }
        catch (const invalid_argument& err)
        {
            cout << "Error: " << err.what() << endl;
        }
    }
} 

/**scaffolding for running the accumulator*/
int main()
{
    try
    {
        accumulator acc;
        acc.print_instructions();

        do
        {
            acc.store_doubles();
            acc.print_sum_doubles();

        } while (acc.should_try_again());
        

    }
    catch (...)
    {
        cout << "FATAL ERROR";
        return -1;
    }
    return 0;
}

/*
Calculator calc;

do
{
    calc.read_input();
    calc.perform_calculation();
    calc.print_output();
}
while(calc.keep_running());*/
