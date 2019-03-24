#include "exercise_08.h"

void fileMerge(string file_one, string file_two)
{
    ifstream first{file_one};
    ifstream second{file_two};
    ofstream ost{"new_file"};

    while (true)
    {
        string contents;
        if (!(first >> contents))
        {
            break;
        }
        ost << contents << " ";
    }
    
    while (true)
    {
        string contents;
        if (!(second >> contents))
        {
            break;
        }
        ost << contents << " ";
    }
}
