#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>



void drill_1()
{
    const Point py(50,50);
    Simple_window win(py, 1000, 800, "Drill 1");
    win.wait_for_button();    
}

int main()
{
    try
    {
        drill_1();
    }
    catch (...)
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}