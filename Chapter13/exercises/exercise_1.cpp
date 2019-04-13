#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>

void exercise_1()
{
    Simple_window win(Point(50,50), 1000, 600, "Exercise 1");
    Point py(500,300);
    Arc arc(py, 200, 100, 50, 310);
    arc.set_color(Color::red);
    win.attach(arc);
    win.wait_for_button();
}

int main()
{
    try
    {
        exercise_1();
    }
    catch(...)
    {
        cout << "MAJOR ERROR!" << endl;
        return -1;
    }
    return 0;    
}
