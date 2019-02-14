#include "exercise_06.h"

void f()
{
    book p("Pride and Pejudice", "Jane Austin", ISBN('1', '2', '3', 'a'), date(22, 2, 1813));
    p.checkin();
    if (p.isCheckedIn() == true)
    {
        cout << p.thisTitle() << " is checked in." << endl;
    }
    cout << p.thisAuthor() << endl << p.thisISBN() << endl;
    book s("Pride and Pejudice", "Jane Austin", ISBN('1', '2', '3', 'a'), date(22, 2, 1813));
    cout << s;
    cout << p;
    if (s.operator!=(p))
    {
        cout << "not the same ISBN";
    }
    else 
    {
        cout << "the same ISBN";
    }
}

int main()
{
    f();
}