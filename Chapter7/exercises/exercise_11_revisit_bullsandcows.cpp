/*

Old chapter 5 exercise 13


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

void unique_rands (int seed, int members, vector <int> & a);
void check_entry (string a, string & e, vector <int> & guess);

int main ()
{
    for (int i = 1; ;i++)
    {
        int seed;
        int answer_size = 4;
        if (i == 1)
        cout << "Please enter a seed number:";
        else
        cout << "\nPlease enter a new seed number:";
        cin >> seed;
        vector <int> guess;
        vector <int> answer;
        unique_rands(seed, answer_size, answer);
        do
        {
            vector <int> guess = { 10, 10, 10, 10 };
            int cow = 0;
            int bull = 0;
            cout << "Enter a guess (4 integers between 0 and 9):";
            for (int i = 0; i < answer.size(); i++)
            {
                string entry;
                check_entry(entry, entry, guess);
                guess[i] = stoi(entry);
            }
            for (int i = 0; i < answer.size(); i++)
            {
                if (answer[i] == guess[i])
                bull += 1;
                else
                for (int j = 0; j < answer.size(); j++)
                {
                    if (answer[i] == guess[j])
                    cow += 1;
                }
            }
            cout << "You scored " << cow << " cows and " << bull << " bulls." << endl;
        }
        while (guess != answer);
        cout << "Congratulations! ";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << guess[i];
        }
        cout << " is the correct answer!" << endl;
    }
}

void unique_rands (int seed, int members, vector <int> & a)
{
        srand(seed);
        a.push_back(rand() % 10);
        for (int j = 1; j < members; j++)
        {
            a.push_back(rand() % 10);
            for (int k = 0; k < a.size() - 1; k++)
            {
            int instances = 0;                                                              Think i found a bug whereby this function doesn't
            if (a[k] == a[j])                                                               ensure the random numbers of the vector are unique
            instances += 1;
            }
        }
}

void check_entry (string a, string & e, vector <int> & guess)
{
    cin >> a;
    while ((a != "0" && a != "1" && a != "2" && a != "3" && a != "4" && a != "5" && a != "6" && a != "7" && a != "8"
     && a != "9") || stoi(a) == guess[0] || stoi(a) == guess[1] || stoi(a) == guess[2] || stoi(a) == guess[3])
    {
        cout << "Your guess must be between 0 and 9 and not have been used previously this round. Try again: ";
        cin >> a;
    }
    e = a;
}
*/


/*
New exercise 13

This program is a version of the game cows and bulls that improves upon the previous version above.
It has been written for an exercise in the book by Bjarne Stroustrup 'Programming principles and practiceusing C++'.
Specifically chapter 7 exercise 11. 

Revised by John Woods January 2019
Created by John Woods January 2019

*/


#include "../stdlibfacilities.h"

/** Class the hande the game */
class BullsAndCows
{
public:
    void print_instruction();
    void play_game();                                                      // Should these be classes themselves?
    bool should_play_again();
    
private:                                                                
    void answer_generator();
    void guess_handler();
    void guess_checker();

    void output_score();
    void count_bulls_and_cows();
    void is_cow(int i);
    int check_input();
    void seed_generator();
    bool is_new_seed();
    bool is_unique(int val, vector<int> & vec);

    /** All of the answers */
    vector<int> answers;
    /** All of the guesses */
    vector<int> guesses;
    vector<int> used_seeds;
    int seed = 0;
    int round = 1;
    int bulls = 0;
    int cows = 0;
    bool correct = false;
    bool again = true;
};

bool BullsAndCows::should_play_again()
{
    string str;
    while (true)
        try
        {
            cout << "Would you like to play again? (y/n): ";
            cin >> str;
            if (str != "y" and str != "n")
                throw invalid_argument("input can only be a 'y' or 'n'");
            if (str == "n")
            {
                again = false;
                cout << "Goodbye." << endl;
                return false;
            }
            else
            {
                again = true;
                correct = false;
                round++;
                used_seeds.push_back(seed);
                return true;
            }
        }
        catch (const exception &err)
        {
            cout << "Error: " << err.what() << endl << "Lets try again.." << endl;
        }
}

bool BullsAndCows::is_unique(int val, vector<int> & vec)
{
    for (auto value:vec)                                                                    // Would it be better to use answers directly here 
        {                                                                                   // rather than this reference
            if (value == val)
            {
                return false;
            }
        }
        return true;
}

void BullsAndCows::output_score()
{
    cout << "You scored " << bulls << " bull";
    if (bulls != 1)
    {
        cout << "s";
    }
    cout << " and " << cows << " cow";
    if (cows != 1)
    {
        cout << "s";
    } 
    cout << "." << endl;
    if (bulls == 4)
    {
        cout << "Congratulations. You guessed right!" << endl;
    }
    else
    {
        cout << "Try again!" << endl;
    }   
}

void BullsAndCows::is_cow(int guess)
{
    for (auto value:answers)
        if (guess == value)
            {
                cows++;
                return;
            }
}

void BullsAndCows::count_bulls_and_cows()
{
    for (int i = 0; i < guesses.size(); i++)
    {
        if (guesses[i] == answers[i])
        {
            bulls++;
        }
        else
        {
            is_cow(guesses[i]);
        }
    }
}

bool BullsAndCows::is_new_seed()
{
    for (auto value:used_seeds)
        if (seed == value)
            return false;
    return true;
}

int BullsAndCows::check_input()
{
    string str;
    cout << "Enter a guess: ";
    while (true)
        try
        {
            cin >> str;
            int d = stoi(str);
            if (d < 0 or d > 9)
                throw invalid_argument("guesses can only be the numbers 0 - 9.");
            if (d == guesses[0] or d == guesses[1] or d == guesses[2] or d == guesses[3])
                throw invalid_argument("guesses can only be used once.");
            return d;
        }
        catch(const exception& err)
        {
            cout << "Input error: " << err.what() << endl << "Try again: ";
        }    
}

void BullsAndCows::guess_checker()
{
    bulls = 0;
    cows = 0;
    count_bulls_and_cows();
    output_score();
    if (bulls == 4)
    {
        correct = true;
    }    
}


void BullsAndCows::guess_handler()
{
    guesses = {10, 10, 10, 10};
    for (auto &values:guesses)
        values = check_input();
}


void BullsAndCows::answer_generator()
{
    srand(seed);
    answers = {10,10,10,10};
    for (auto &value:answers)
    {
        int val;
        val = rand() % 10;
        while (BullsAndCows::is_unique(val, answers) == false)            
            val = rand() % 10;        
        value = val;                                                                        // Any way to do this in two lines rather than 3?
    }                                                                                       // Would it be better to not pass answers as reference
}                                                                                           // and just access it from is_unique?

void BullsAndCows::seed_generator()
{
    if (round == 1)
    {
        cout << "Please enter a seed number: ";                                                     // didn't bother checking this input as it 
        cin >> seed;                                                                                // would be accepted no matter what was entered.
    }                                                                                               // should I have checked it?
    else                                                                                            // I mean the input will always be converted to
    {                                                                                               // an int.
        cout << "Please enter a new seed number: ";
        cin >> seed;
        while (is_new_seed() == false)
        {   
            cout << "That's not a new seed" << endl << "Try again: ";                                // is it ok to call new_seed like this?
            cin >> seed;                                                                          
        } 
    }
}


//instructions on how to play
void BullsAndCows::print_instruction()
{
    cout << "Welcome to bulls and cows" << endl << "The aim of the game is to guess the 4 secret numbers and the order they are in." << endl
    << "If you guess a number and you get it in the right position, you get a bull." << endl << 
    "If you guess the right number but in the wrong position, you get a cow" << endl << "The guessing continues until you have four bulls." <<
    endl << "Good luck!" << endl; 
}

//handle the game loop
void BullsAndCows::play_game()                                               // Orighaly was not part of BullsAndCows so should i 
{                                                                                 // still call the member functions with the game_instance
    while (again == true)
    {
        seed_generator();
        answer_generator();
        while (correct == false)                                    // Would it make more sense to a reader 
        {                                                                         // if correct is called after guess checker? Would it 
            guess_handler();                                        // be better to use a do while loop or is there another way
            guess_checker();                                        // to do this?
        }
    }
}


///////
/////// 
///////

int main()
{
    try
    {
        BullsAndCows game;
 
        game.print_instruction();

        do
        {
           game.play_game();

        } while (game.should_play_again());
    }
    catch(...)
    {
        cout << "ERROR";
        return -1;
    }
    return 0;
}





// For names of functions is it better to use a verb or an adjective? For instance the 'seed_generator' function: would it be better to call it 
// that or to call it 'generate_seed'?