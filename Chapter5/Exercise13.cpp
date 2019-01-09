#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

void unique_rands (int seed, int members, vector <int> & a);

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
        vector <int> guess = { 10, 10, 10, 10 };
        vector <int> answer;
        unique_rands(seed, answer_size, answer);
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
            int instances = 0;
            if (a[k] == a[j])
            instances += 1;
            }
        }
}