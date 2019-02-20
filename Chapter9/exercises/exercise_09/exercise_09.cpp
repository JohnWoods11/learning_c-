#include "exercise_09.h"

void f()
{
    book pride_and_prejudice ("Pride and Prejudice", "Jane Austin", Genre::fiction, ISBN('1', '1', '1', 'a'), date(20, 11, 1813));
    book why_nations_fail ("Why Nations Fail", "Daron Acemoglu & James A. Robinson", Genre::nonfiction, ISBN('2','2','2','b'), date(10, 8, 2012));
    Patron john ("John", "12345", 0);
    Patron james ("James", "23456", 100);

    Patron jeff ("Jeff", "34567", 0);
    book eyeless_in_gaza ("Eyeless in Gaza", "Aldous Huxley", Genre::fiction, ISBN('3','3','3','c'), date(20, 3, 1936));
    Library myLibrary;
    myLibrary.addBook(pride_and_prejudice);
    myLibrary.addBook(why_nations_fail);
    myLibrary.addPatron(john);
    myLibrary.addPatron(james);
    for (auto patron:myLibrary.whoOwesFees())
    {
        cout << patron.seeName() << endl;
    }
    myLibrary.checkOutBook(james, why_nations_fail);
    myLibrary.checkOutBook(john, pride_and_prejudice);
    myLibrary.checkOutBook(jeff, why_nations_fail);
    myLibrary.checkOutBook(john, eyeless_in_gaza);
    for (auto transaction:myLibrary.transactionLedger())
    {
        cout << transaction.b << endl << transaction.p.seeName() << endl << endl;  
    }
}

int main()
{
    f();
}
