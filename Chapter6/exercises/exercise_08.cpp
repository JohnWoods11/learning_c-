#include "../stdlibfacilities.h"

char check_input()
{
    char input;
    cin >> input;
    while (input < 'a' or input > 'z') 
    {
        cout << input << " is not a lowercase letter, please try again." << endl;
        cin >> input;
    }
    return input;
}


void take_guess(vector <char> & guess)
{
    cout << "\nEnter a guess (4 lower-case letters (a - z))" << endl;
    for (int i = 0; i < guess.size(); i++)                                                      //tried to assign guess with a range for loop
       guess[i] = check_input();                                                                //for (auto value:guess)
}                                                                                               //   value = check_input();
                                                                                                //but would not assign, because reference?
void check_guess(vector <char> & guess, vector <char> & answer, int & bulls, int & cows)
{
    for (int i = 0; i < guess.size(); i++)
        if (guess[i] == answer[i])
            bulls += 1;
        else
            for (auto value:answer)
                if (guess[i] == value)
                    cows +=1;
}

bool give_feedback(vector <char> & guess, vector <char> & answer)
{
    int bulls = 0;
    int cows = 0;
    check_guess(guess, answer, bulls, cows);
    if (bulls == 4)
    {
        cout << "You are correct, congratulations!" << endl;
        return true;
    }    
    else
    {
        cout << "Bulls: " << bulls << endl << "Cows: " << cows << endl;
        return false;
    }
}

void bulls_and_cows()
{
    vector <char> answer{'a', 'l' ,'p', 't'};
    vector <char> guess(4);
    take_guess(guess);                                                     
    while (give_feedback(guess, answer) != true)                                            
        take_guess(guess);
}

int main ()
{
    try
    {
        bulls_and_cows();
    }
    catch (...)
    {
        cout << "MAJOR ERROR" << endl;
    }
}