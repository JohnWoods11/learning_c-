#include "../stdlibfacilities.h"

const int number_of_people = 5;
const int oldest_person_ever = 123;

/**Return a vector of a specified number of name strings*/
vector<string> read_names()
{
    vector<string> names;
    string name;
    while (names.size() < number_of_people)
    {
        cin >> name;
        names.push_back(name);
    }
    return names;
}

/**Return a vector of a specified number of age integers*/
vector<int> store_ages()
{
    vector<int> ages;
    int age;
    while (ages.size() < number_of_people)
    {
        try
        {
            if (cin >> age)
            {
                if (age < 0 or age > oldest_person_ever)
                {
                    throw invalid_argument(to_string(age) + " is either below 0 or older than anyone has ever lived.");
                }
                ages.push_back(age);
            }
            else
            {
                cout << "Age must be an integer." << endl;
                cin.clear();
            }            
        }
        catch(const std::exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }    
    }
    return ages;
}

/**Return a sorted version of a vector of name strings*/
vector<string> sort_names(vector<string> names)
{
    sort(names.begin(), names.end());
    return names;
}

/**Reallign ages with owners after name sorting*/
vector<int> sort_ages(const vector<int>& ages, const vector<string>& unsorted_names, const vector<string>& sorted_names)
{
    vector<int> sorted_ages;
    for (auto value:sorted_names)
    {
        for (int i = 0; i < sorted_names.size(); i++)
        {
            if (unsorted_names[i] == value)
            {
                sorted_ages.push_back(ages[i]);
            }
        }
    }
}

/*Print name and age pairs*/
void print_name_age_pairs(const vector<int>& ages, const vector<string>& names)
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << ": " << ages[i] << endl;
    }
}

/**Function control for program*/
void exercise_07()
{
    cout << "Please enter " << number_of_people << " names:" << endl;
    vector<string> unsorted_names = read_names();
    cout << "please enter the ages of those " << number_of_people << " people in the same order:" << endl;
    vector<int> unsorted_ages = store_ages();
    print_name_age_pairs(unsorted_ages, unsorted_names);
    vector<string> sorted_names = sort_names(unsorted_names);
    vector<int> sorted_ages = sort_ages(unsorted_ages, unsorted_names, sorted_names);
    print_name_age_pairs(sorted_ages, sorted_names);
}

/* Would this be better?

void function_control()
{
    vector<string> unsorted_names;
    vector<int> unsorted_ages;
    vector<string> sorted_names;
    vector<int> sorted_ages;
    unsorted_names = read_names();
    unsorted_ages = store_ages();
    print_name_age_pairs(unsorted_ages, unsorted_names);
    sorted_names = sort_names(unsorted_names);
    sorted_ages = sort_ages(unsorted_ages, unsorted_names, sorted_names);
    print_name_age_pairs(sorted_ages, sorted_names);
}
*/

int main()
{
    try 
    {
        exercise_07();
    }
    catch(...)
    {
        cout << "MAJOR ERROR" << endl;
        return -1;
    }
    return 0;
}