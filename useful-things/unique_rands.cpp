#include <vector>
#include <cstdlib>
using namespace std;

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
