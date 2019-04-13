#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>

void exercise_2()
{
    Simple_window win(Point(50,50), 1000, 600, "Exercise 1");
    Point py(500,300);
    Box box(py, 100, 200, 2);
    box.set_color(Color::red);
    win.attach(box);
    win.wait_for_button();
}

int main()
{
    try
    {
        exercise_2();
    }
    catch(...)
    {
        cout << "MAJOR ERROR!" << endl;
        return -1;
    }
    return 0;    
}
