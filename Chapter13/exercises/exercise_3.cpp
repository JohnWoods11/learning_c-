#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>

void exercise_3()
{
    Point py(50,50);
    Simple_window win(py, 1000, 600, "Exercise 3");
    
    Vector_ref<Arrow> arrows;

    for (int x = 0; x <= 600; x+= 20)
    {
        for (int y = 0; y <= 600; y+=20)
        {
            if (x == 0 or x == 600 or y == 0 or y == 600)
            {
                arrows.push_back(new Arrow(Point(x,y), Point(300,300)));
            }
        }
    }
    

    for (int i = 0; i < arrows.size(); i++)
    {
        win.attach(arrows[i]);
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