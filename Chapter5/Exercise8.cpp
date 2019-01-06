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
    cout << "The sum of the first " << n << " numbers ( ";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += entries[i];
        cout << entries[i] << " ";
    }
    cout << ") is " << sum << "." << endl;    
    return 0;   
}
}