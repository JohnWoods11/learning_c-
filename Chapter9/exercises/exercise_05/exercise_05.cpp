#include "exercise_05.h"

void f()
{
    book p("Pride and Pejudice", "Jane Austin", ISBN('1', '2', '3', 'a'), date(22, 2, 1813));
    p.checkin();
    if (p.isCheckedIn() == true)
    {
        cout << p.thisTitle() << " is checked in." << endl;
    }
    cout << p.thisAuthor() << endl << p.thisISBN() << endl;
}

int main()
{
    f();
}