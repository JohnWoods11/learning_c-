#include <iostream>
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