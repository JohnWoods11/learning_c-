/* 
Analysis

This program must:
Give user instructions for use
Ask user for the type of calculation to be run
Take two integers
Do the calculation requested with the integers provided
Print the result
It must also refuse bad input at any stage
*/

/*
Design

factorial()
evaluate factorial

nums_check(nums)
ask for two integers for calculation
check number inputs are valid
throw invalid input exceptions with error descriptions

calc_check(calc)
ask which calculation user wants,
check string inputs are valid
throw invalid input exceptions with error descriptions


permutation(nums)
calculate number of permutations
use equation - P(a,b)= a! / (a-b)!
return the answer

combination(nums)
calculate number of combinations
use equation - C(a,b) = P(a,b) / b!
return the answer

combination_permutation_calc()
num_check the input
calc_check the input
run relevant calculation (permutation(nums) or combination(nums)),
print result of calculation,
ask if user is finished,
break or repeat,

int main ()
try combination_permutation_calc,
catch all exceptions,
return 0,

*/


#include "../stdlibfacilities.h"

long long factorial(long long val)
{
    if (val == 0)                                           //0! evaluates to 1
    {                                                       
        return 1;              
    }                                 
    if (val > 2)                                            //calculates factorial (skips 2*1 step)          
    {
        val *= factorial(val-1);
    }
    if (val < 0)
    {
        throw out_of_range("one or both integers were too big for this calculator");
    }
    return val;
}

int nums_check(int &possible_nums, int &set_size)
{
    cout << "Please enter the two integers you would like to see the permutations or combinations for." << endl << "Amount of possible numbers: ";
    cin >> possible_nums;
    if (cin.fail())
    {
        throw invalid_argument("input must be an integer");
    }
    cout << "Amount of numbers in set: ";
    if (cin.fail())
    {
        throw invalid_argument("input must be an integer");
    }
    cin >> set_size;
    if (set_size > possible_nums)
    {
        throw invalid_argument("set size can not be larger than amount of possible numbers");
    }
    if (set_size < 0)
    {
        throw invalid_argument("set size or amount of possible numbers can not be negative");
    }
    if (set_size == 0)
    {
        throw invalid_argument("set size must be larger than zero");
    }
}

int calc_check()
{
    cout  << "Which type of calculation would you like?" << endl << "Enter 'p' for permutation or 'c' for combination." << endl <<
    "Alternitavely enter 'b' for both or 'q' to quit." << endl << "Command: ";
    string command;
    cin >> command;
    if (command == "p")
    {
        return 1;
    }
    else if (command == "c")
    {
        return 2;
    }
    else if (command == "b")
    {
        return 3;
    }
    else if (command == "q")
    {
        return 4;
    }
    else
    {
        throw invalid_argument("Command " + command + " not recognised.");
    }
}

int permutations(int num1, int num2)
{
    return factorial(num1) / factorial(num1 - num2);
}

int combinations(int num1, int num2)
{
    return permutations(num1, num2) / factorial(num2);
}

void combination_permutation_calc()
{
    cout << "Welcome to the combination and permutation calculator." << endl;
    string repeat;
    do
    {
        int possible_nums;
        int set_size;
        nums_check(possible_nums, set_size);
        switch (calc_check())
        {
            case 1:
            {
                cout << "Number of permutations for (" << possible_nums << "," << set_size << ") : " 
                << permutations(possible_nums, set_size) << endl;
                break;
            }
            case 2:
            {
                cout << "Number of combinations for (" << possible_nums << "," << set_size << ") : " 
                << combinations(possible_nums, set_size) << endl;
                break;
            }
            case 3:
            {
                cout << "Number of permutations for (" << possible_nums << "," << set_size << ") : " 
                << permutations(possible_nums, set_size) << endl;
                cout << "Number of combinations for (" << possible_nums << "," << set_size << ") : " 
                << combinations(possible_nums, set_size) << endl;
                break;
            }
            case 4:
            {
                cout << "Goodbye." << endl;
                break;
            }
        }
        cout << "Would you like to make another calculation? (y , n): ";
        cin >> repeat;
        if (repeat != "y" and repeat != "n")
        {
        throw invalid_argument("command " + repeat + " not recognised");
        }
    }
    while (repeat == "y");
    cout << "Goodbye.";
}

int main()
{
    try
    {
        combination_permutation_calc();
    }
    catch (invalid_argument &err)
    {
        cout << "Error: " << err.what()  << endl;
    }
    catch (out_of_range &err)
    {
        cout << "Error: " << err.what() << endl;
    }
    catch (...)
    {
        cout << "MAJOR ERROR." << endl;
        return -1;
    }
    return 0;
}

