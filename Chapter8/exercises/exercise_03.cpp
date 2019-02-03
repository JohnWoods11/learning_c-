#include "../stdlibfacilities.h"
#include "exercise_headers.h"

/** transform empty vector into a vector of fibonacci numbers with specified starting numbers and end size*/

void fibonacci (int x, int y, vector<int>& v, int n)
{
    if (n < v.size())
        throw invalid_argument("vector size must be at least two.");
    v.push_back(x);
    v.push_back(y);
    while (v.size() <= n)
    {
        v.push_back(v[v.size()-1] + v[v.size()-2]);
    }
}

int main()
{
    try
    {
        vector<int> empty;
        fibonacci(1, 2, empty, 10);
        print("fibonacci", empty);
    }
    catch(const std::exception& e)
    {
        cout << "ERROR: " << e.what() << endl;
    }
    
}