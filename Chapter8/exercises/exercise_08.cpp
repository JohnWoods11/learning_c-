#include "../stdlibfacilities.h"


/**Have user set number of people to be listed*/
int define_list_size()
{
    string str;
    while (true)
    {
        try
        {
            cin >> str;
            int list_size = stoi(str);
            if (list_size < 1)
            {
                throw invalid_argument("the list must contain at least one person.");
            }
            return list_size;
        }
        catch(invalid_argument& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}

/**Check a word in a vector is unique*/
bool is_unique_word(vector<string>& used_words, string new_word)
{
    for (auto word:used_words)
    {
        if (new_word == word)
        {
            return false;
        }
    }
    return true;
}

/**Return a vector of a specified number of name strings*/
vector<string> read_names(int number_of_people)
{
    vector<string> names;
    string name;
    while (names.size() < number_of_people)
    {
        try
        {
            cin >> name;
            if (is_unique_word(names, name) == false)
            {
                throw invalid_argument("name already used.");
            }
            names.push_back(name);
        }
        catch(invalid_argument& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    return names;
}

/**Return a vector of a specified number of age integers*/
vector<int> store_ages(int number_of_people)
{
    const int oldest_person_ever = 123;
    vector<int> ages;
    string str;
    while (ages.size() < number_of_people)
    {
        try
        {
            cin >> str;
            int age = stoi(str);
            if (age < 0 or age > oldest_person_ever)
            {
                throw invalid_argument(age + " is either below 0 or older than anyone has ever lived.");
            }
            ages.push_back(age);
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
                break;
            }
        }
    }
    return sorted_ages;
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
    cout << "how many people would you like to include in your list?" << endl;
    const int number_of_people = define_list_size();
    cout << "Please enter " << number_of_people << " names:" << endl;
    vector<string> unsorted_names = read_names(number_of_people);
    cout << "please enter the ages of those " << number_of_people << " people in the same order:" << endl;
    vector<int> unsorted_ages = store_ages(number_of_people);
    cout << "unsorted pairs:" << endl;
    print_name_age_pairs(unsorted_ages, unsorted_names);
    vector<string> sorted_names = sort_names(unsorted_names);
    vector<int> sorted_ages = sort_ages(unsorted_ages, unsorted_names, sorted_names);
    cout << "sorted pairs:" << endl;
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