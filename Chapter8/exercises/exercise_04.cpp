#include "../stdlibfacilities.h"
#include "exercise_headers.h"

/** transform empty vector into a vector of fibonacci numbers with specified starting numbers and end size that returns last number before
 * integer overflow if it occurs*/

void fibonacci (int x, int y, vector<int>& v, int n)
{
    if (n < v.size())
        throw invalid_argument("vector size must be at least two.");
    v.push_back(x);
    v.push_back(y);
    while (v.size() <= n)
    {
        v.push_back(v[v.size()-1] + v[v.size()-2]);
        if (v[v.size()-1] < v[v.size()-2])
            {
                cout << v[v.size()-2] << " - Largest fibonacci number to fit in an int." << endl;
                break; 
            }
    }
}

#include <limits>

int main()
{
    auto s = std::numeric_limits<int>::max();

    try
    {
        vector<int> empty;
        fibonacci(1, 2, empty, 1000);                   //Just used an arbitrarilly large number here, should i have done it another way?
        print("fibonacci", empty);
    }
    catch(const std::exception& e)
    {
        cout << "ERROR: " << e.what() << endl;
    }
    
}