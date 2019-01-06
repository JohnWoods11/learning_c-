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
vector <int> entries;
int entry;
while (cin >> entry) entries.push_back(entry);
if (entries.size() < n)
{
    cout << "Error you asked for a sum of more numbers than you entered"<<endl;
    return 1;
}
else
{
int sum = 0;
for (int i = 0; i < n; i++)
{
    sum += entries[i];
}
if (sum % 1 != 0)
{
    cout << "The result can not be displayed as an integer.";
}
else
{
    cout << "The sum of the first " << n << " numbers ( ";
    for (int i = 0; i < n; i++)
    {
        cout << entries[i] << " ";
    }
    cout << ") is " << sum << "." << endl;    
    return 0;
}
}
}