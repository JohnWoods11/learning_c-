#include "../stdlibfacilities.h"

/**Returns a reversed copy of a vector of integers*/
vector<int> swap_copy(vector<int> list)
{
    for (int i = 0; i < list.size()/2; i++)
        {
            swap(list[i], list[list.size()-(1 + i)]);
        }
    return list;
}

/**Reverses a vector of integers*/
void swap_vec(vector<int>& list)
{
    for (int i = 0; i < list.size()/2; i++)
        {
            swap(list[i], list[list.size() - (1 + i)]);
        }
}

int main()
{
    vector<int> nums {1, 1, 1, 1, 2, 2, 2, 2, 2};
    vector<int> nums2 = swap_copy(nums);
    for (auto value:nums2)
    {
        cout << value << ", "; 
    }
    cout << endl;
    swap_vec(nums2);
    for (auto value:nums2)
    {
        cout << value << ", "; 
    }    
    cout << endl;
}