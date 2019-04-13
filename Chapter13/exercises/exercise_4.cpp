#include "exercise_04/exercise_4.h"


void exercise_4()
{
    Rectangle r(Point(50,50), 300, 200);
    Simple_window win(Point(50,50), 500, 500, "Exercise 4");
    Vector_ref<Mark> marks;
    marks.push_back(new Mark(*n(r), 'x'));
    marks.push_back(new Mark(*ne(r), 'x'));
    marks.push_back(new Mark(*e(r), 'x'));
    marks.push_back(new Mark(*se(r), 'x'));
    marks.push_back(new Mark(*s(r), 'x'));
    marks.push_back(new Mark(*sw(r), 'x'));
    marks.push_back(new Mark(*w(r), 'x'));
    marks.push_back(new Mark(*nw(r), 'x'));
    marks.push_back(new Mark(*center(r), 'x'));
    for (int i = 0; i < marks.size() ; i++)
    {
        marks[i].set_color(Color::red);
        win.attach(marks[i]);
    }
    win.wait_for_button();
}


int main()
{
    try 
    {
        exercise_4();
    }
    catch (...)
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}