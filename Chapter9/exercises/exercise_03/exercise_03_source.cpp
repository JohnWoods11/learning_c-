#include "exercise_03.h"

Name_pairs::Name_pairs()
{
    assertSane();
}

Name_pairs::Name_pairs(const Name_pairs &other):name(other.name), age(other.age)
{}

Name_pairs::~Name_pairs()
{}

Name_pairs& Name_pairs::operator= (const Name_pairs& other)
{
    if (this->operator!=(other))
    {
        name = other.name;
        age = other.age;
    }
    return *this;
}

bool Name_pairs::operator!= (const Name_pairs& other) const
{   
    if (name != other.name and age != other.age)
        return true;
    else 
        return false;
}

bool Name_pairs::operator== (const Name_pairs& other) const
{
    return not this->operator!=(other);
}

ostream& operator<< (ostream &out, const Name_pairs &pairs)
{
    out << pairs.to_string();
    return out;
}

string Name_pairs::to_string() const
{
    string everyone;
    for (int i = 0; i < name.size(); i++)
    {
        everyone += name[i] + ": " + std::to_string(age[i]) + "\n";
    }
    return everyone;
}

/** Checks if parameter is a double*/
double to_double(string input)
{
    return stod(input);
}

/** Gets name input from user*/
void Name_pairs::read_names()
{
    cout << "Please enter all the names in your name/age pairs seperated by whitespace:" << endl << "(type 'quit' to exit name input)" << endl;
    string temp;
    while (true)
    {
        cin >> temp;
        while (this->is_unique_name(temp) == false)
            cin >> temp;
        if (temp == "quit")
            break;
        this->name.push_back(temp);
    }
}

void Name_pairs::read()
{
    if (not this->isEmpty())
    if (this->name.size() != 0 or this->age.size() != 0)
        throw invalid_argument( "You cannot read names twice!");

    this->read_names();
    this->read_ages();
    this->assertSane();
}

/** Gets the corresponding age for each name the user input*/
void Name_pairs::read_ages()
{
    cout << "Now enter the corresponding age to each name:" << endl;

    for (auto value: this->name)
    {
        double number = 0;
        bool has_number = false;

        do
        {
            cout << value << ": ";

            string number_string;

            cin >> number_string;

            try
            {
                number = to_double(number_string);
                has_number = true;
            }
            catch(...)
            {
                cout << "ERROR MESSAGE";
            }
        }
        while (not has_number);

        this->age.push_back(number);
    }

    this->assertSane();
}

/** Sorts stored names and ages lexicographicaly*/
void Name_pairs::sort()
{
    this->assertSane();

    vector<string> temp_names = name;
    vector<double> temp_ages;
    std::sort(name.begin(), name.end());
    for (auto value: name)
    {
        for (int i = 0; i < name.size(); i++)
        {
            if (temp_names[i] == value)
            {
                temp_ages.push_back(age[i]);
            }
        }
    }
    age = temp_ages;
}

/** Checks if name is unique during runtime*/
bool Name_pairs::is_unique_name(string input) const
{
    for (auto value: this->name)
    {
        if (value == input)
            return false;
    }
    return true;
}

bool Name_pairs::isEmpty() const
{
    if (age.size() == 0 or name.size() == 0)
        return true;
    else 
        return false;
}

void Name_pairs::assertSane() const
{
    if (age.size() != name.size())
        throw invalid_argument("Data corrupted - " + std::to_string(name.size()) + " names but " +  std::to_string(age.size()) + " ages.");
}

