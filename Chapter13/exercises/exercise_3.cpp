#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>

void exercise_3()
{
    Point py(50,50);
    Simple_window win(py, 1000, 600, "Exercise 3");
    for (int i = 0 ; i < 600 ; i+=200)
    {
        for (int j = 0; j < 600; j+=200)
        {
            Arrow ar(Point(j,i), Point (300,300));
            ar.set_color(Color::red);
            win.attach(ar);
            
            win.wait_for_button();
        }
    }
    win.wait_for_button();
}


int main()
{
    try
    {
        exercise_3();
    }
    catch(...)
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}