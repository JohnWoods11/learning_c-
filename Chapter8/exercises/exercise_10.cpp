#include "../stdlibfacilities.h"

void maxv(vector<int>& nums)
{
    int largest = nums[0];
    for (auto value:nums)
    {
        if (value > largest)
        {
            largest = value;
        }
    }
    cout << largest << endl;
}

void maxv(vector<double>& nums)
{
    double largest = nums[0];
    for (auto value:nums)
    {
        if (value > largest)
        {
            largest = value;
        }
    }
    cout << largest << endl;
}  

void maxv(vector<string>& words)
{
    string largest = words[0];
    for (auto value:words)
    {
        if (value > largest)
        {
            largest = value;
        }
    }
    cout << largest << endl;
}

int main()
{
    try
    {
    vector<int> ints {3, 4, 7, 8, 12, 4};
    vector<string> words {"some", "thing", "or", "other"};
    vector<double> nums {3.2, 2.4, 6.7, 2};
    maxv(ints);
    maxv(words);
    maxv(nums);   
    }
    catch(...)
    {
        cout << "MAJOR ERRROR" << endl;
        return -1;
    }
    return 0;
}