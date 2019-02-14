#include "exercise_03.h"

void f()
{
    Name_pairs team;
    team.read();
    cout << team;
    team.sort();
    cout << team;

    Name_pairs new_team(team);
    Name_pairs other = team;
}


int main()
{
    try
    {
        f();
    }
    catch(...)
    {
        cout << "Fatal error.";
        return -1;
    }
    return 0;
}