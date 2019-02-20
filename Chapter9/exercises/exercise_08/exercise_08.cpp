#include "exercise_08.h"

void f()
{
    book p("Pride and Pejudice", "Jane Austin", Genre::fiction, ISBN('1', '2', '3', 'a'), date(22, 2, 1813));
    p.checkin();
    if (p.isCheckedIn() == true)
    {
        cout << p.thisTitle() << " is checked in." << endl;
    }
    cout << p.thisAuthor() << endl << p.thisISBN() << endl;
    book s("Pride and Pejudice", "Jane Austin", Genre::fiction, ISBN('1', '2', '3', 'a'), date(22, 2, 1813));
    cout << s;
    cout << p;
    if (s.operator!=(p))
    {
        cout << "not the same ISBN" << endl;
    }
    else 
    {
        cout << "the same ISBN" << endl;
    }
    Patron john ("John", "013344", 20);
    cout << john.seeName() << endl << john.seeCredit() << endl << john.seeCardNumber() << endl;
    john.setFee(1000);
    cout << john.seeCredit() << endl;
    if (patronOwesFee(john))
    {
        cout << "John owes a fee" << endl;
    }
    john.setFee(-2);
    cout << john.seeCredit();
    
}

int main()
{
    f();
}
