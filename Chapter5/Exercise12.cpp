#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main ()
{
    vector <int> answer = { 3, 4, 5, 6 };
   /* answer.push_back(3);
    answer.push_back(4);
    answer.push_back(5);
    answer.push_back(6);*/
    vector <int> guess = { 10, 10, 10, 10 };
/*    guess.push_back(10);
    guess.push_back(10);
    guess.push_back(10);
    guess.push_back(10);*/
    do
    {
        int cow = 0;
        int bull = 0;
        cout << "Enter a guess (4 integers between 0 and 9):";
        for (int i = 0; i < answer.size(); i++)
        {
            int entry;
            cin >> entry;
            guess[i] = entry;
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