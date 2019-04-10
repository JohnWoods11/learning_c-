#include "exercise_16.h"

void parseNumbers(const string &filename)
{
    ifstream ifst(filename);
    map<double,int> numbers_map;
    vector<double> numbers_vector;
    while (ifst)
    {
        double number;
        ifst >> number;
        if (numbers_map.count(number))
        {
            numbers_map[number]++;
        }
        else 
        {
            numbers_map[number] = 1;
            numbers_vector.push_back(number);
        }
    }
    sort(numbers_vector.begin(), numbers_vector.end());
    for (auto number: numbers_vector)
    {
        cout << setw(10) << left << number;
        if (numbers_map[number] > 1)
        {
            cout << setw(10) << left << numbers_map[number];
        }
        cout << endl;
    }
}