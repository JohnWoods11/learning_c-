#include "../stdlibfacilities.h"

/**Returns a reversed copy of a vector of strings*/
vector<string> swap_copy(vector<string> list)
{
    for (int i = 0; i < list.size()/2; i++)
        {
            swap(list[i], list[list.size()-(1 + i)]);
        }
    return list;
}

/**Reverses a vector of strings*/
void swap_vec(vector<string>& list)
{
    for (int i = 0; i < list.size()/2; i++)
        {
            swap(list[i], list[list.size() - (1 + i)]);
        }
}

int main()
{
    vector<string> strings1 {"start", "1", "1", "1", "2", "2", "2", "2", "end"};
    vector<string> strings2 = swap_copy(strings1);
    for (auto value:strings2)
    {
        cout << value << ", "; 
    }
    cout << endl;
    swap_vec(strings2);
    for (auto value:strings2)
    {
        cout << value << ", "; 
    }    
    cout << endl;
}