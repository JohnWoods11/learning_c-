#include "exercise_05/exercise_5.h"


void exercise_5()
{
    Simple_window win(Point(50,50), 600, 600, "Exercise 5");
    Circle c(Point(200,200), 100);
    c.set_color(Color::red);
    win.attach(c);
    Vector_ref<Mark> marks;
    marks.push_back(new Mark (*ne(c), 'x'));
    marks.push_back(new Mark (*nw(c), 'x'));
    marks.push_back(new Mark (*se(c), 'x'));
    marks.push_back(new Mark (*sw(c), 'x'));
    marks.push_back(new Mark (*n(c), 'x'));
    marks.push_back(new Mark (*e(c), 'x'));
    marks.push_back(new Mark (*s(c), 'x'));
    marks.push_back(new Mark (*w(c), 'x'));


    Ellipse f(Point(450,200), 50, 100);
    f.set_color(Color::blue);
    win.attach(f);
    Vector_ref<Mark> marks2;
    marks2.push_back(new Mark (*n(f), 'x'));
    marks2.push_back(new Mark (*e(f), 'x'));
    marks2.push_back(new Mark (*s(f), 'x'));
    marks2.push_back(new Mark (*w(f), 'x'));
    marks2.push_back(new Mark (*ne(f), 'x'));
    marks2.push_back(new Mark (*se(f), 'x'));
    marks2.push_back(new Mark (*sw(f), 'x'));
    marks2.push_back(new Mark (*nw(f), 'x'));
    


    for (int i = 0 ; i < marks.size(); i++)
    {
        marks[i].set_color(Color::red);
        win.attach(marks[i]);
    }

    for (int i = 0 ; i < marks2.size(); i++)
    {
        marks2[i].set_color(Color::red);
        win.attach(marks2[i]);
    }
    win.wait_for_button();
    win.clear();
}


int main()
{
    try 
    {
        exercise_5();
    }
    catch (...)
    {
        cout << "MAJOR ERROR!" << endl;
        return -1;
    }
    return 0;
}