#include "exercise_08.h"

void f()
{
    ifstream ifst("input.txt");
    string text;
    for (string word ; ifst >> word ; )
    {
        text += word + " ";
    }
    toLowerString(text);
    changeWord(text, "don't", "do not");
    changeWord(text, "can't", "cannot");
    cout << makeDictionary(text);
}

int main()
{
    try 
    {
        f();
    }
    catch (...)
    {
        cout << "MAJOR ERROR";
        return -1;
    }
    return 0;
}