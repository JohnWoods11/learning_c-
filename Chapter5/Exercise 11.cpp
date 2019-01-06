#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main ()
{
    int n = 0;
    int first = 0;
    int second = 1;
    cout << "Please enter the number of fibonacci sequences you would like:";
    cin >> n;
    cout << second;
    for (int i = 0; i < n; i++)
    {
        int next = first + second;
        cout << " " << next;
        first = second;
        second = next;
    }
    cout << endl;
    return 0;
}
    