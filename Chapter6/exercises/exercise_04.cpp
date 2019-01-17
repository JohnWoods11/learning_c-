#include "../stdlibfacilities.h"

class Person
{
    public:
    string name;                                //persons name
    int score;                                  //persons score
    Person(string x, int y)                     //make Person token with name and score
        :name (x), score (y){}          
};

vector <Person> score_database;

int input_check(string &name, int &score)
{
    if (cin >> name >> score)
    {
        if (name == "NoName" and score == 0)                                                            //was 'NoName 0' entered
            return 1;
        for (int i = 0; i < score_database.size(); i++)
            if (name == score_database[i].name)                                                         //has this name already been entered
                throw invalid_argument("The name " + name + " has already been entered.");
        return 0;
    }
}


void assign_scores()
{
    cout << "Please enter each persons name followed by their score." << endl << "No duplicate names." << endl << "Enter 'NoName 0' to exit input"
    << endl;
    string name;
    int score;
    while (true)
    {
        if (input_check(name, score) == 1)
        {
            cout << "Exiting input..." << endl;                                            //'NoName 0' was found
            break;
        }
        else                                                                               //'NoName 0' was not found
        {
            Person p = Person(name, score);                                                // is this still known as p in the vector?
            score_database.push_back(p);                                                   // i'm assuming not and that it is now 
        }                                                                                  // known only by its position. 
    }
}

void print_scores()
{
    cout << "Printing scores..." << endl;
    for (int i = 0; i < score_database.size(); i++)
    {
        cout << score_database[i].name << "\t" << score_database[i].score << "." << endl;      //print out all name score pairs
    }
}


int main()
{
try
{
    assign_scores();
    print_scores();
    return 0;
}
catch(const exception &err)
{
    cout << "ERROR: " << err.what() << endl;
    return -1;
}
}