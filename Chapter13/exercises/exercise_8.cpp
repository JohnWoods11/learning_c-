#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>


void exercise_8()
{
    Hexagon h(Point(200,200), 100);
    Simple_window win(Point(50,50), 600, 400, "Exercise 8");
    h.set_color(Color::magenta);
    win.attach(h);
    win.wait_for_button();
    win.clear();
}

int main()
{
    try
    {
        exercise_8();
    }

    catch(const exception &err)
    {
        cout << "Error: " << err.what() << endl;
    }
    catch (...)
    {
        cout << "MAJOR ERROR!" << endl;
        return -1;
    }
    return 0;
}