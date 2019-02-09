#include "../stdlibfacilities.h"


void print_until_s(vector<string> v, string quit)
{
    for (string s: v){
        if (s == quit) return;
        cout << s << '\n'; 
    }
}

void improved_print_until_s(const vector<string>& v, string quit)
{
    for (auto value: v)
    {
        if (value == quit)
        {
            return;
        }
        cout << value << endl;
    }
}
    //A good set of test cases would be inputs containing the quit string to make sure the function won't print it.

void print_until_ss(const vector<string>& v, string quit)
{
    int quit_counter = 0;
    for (auto value: v)
    {
        if (value == quit)
        {
            quit_counter += 1;
        }
        if (quit_counter == 2)
        {
            return;
        }
        cout << value << endl;
    }
}

int main()
{
    vector<string> myvec = {"one", "two", "three", "four", "one", "two", "three", "four"};
    print_until_s(myvec, "three");
    improved_print_until_s(myvec, "three");
    print_until_ss(myvec, "three");
}