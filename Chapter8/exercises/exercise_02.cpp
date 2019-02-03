#include "../stdlibfacilities.h"
#include "exercise_headers.h"

/** Print out a labeled vector of integers*/

void print (string label, vector<int> &list)
{
    cout << label << ": ";
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i];
        if (i < list.size() - 1)
            cout << ", ";
    }
    cout << "." << endl;
}
