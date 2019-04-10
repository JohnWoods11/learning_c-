#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>


void drill_2()
{
    const Point py(50,50);
    Simple_window win(py, 1000, 800, "Drill 2");
    Lines grid;

    int grid_rows = 8;
    int grid_collumns = 8;
    int grid_width = 800;
    int grid_height = 800;

    // draw horizontal lines
    for (int i = 0; i <= grid_rows ; i ++ )
    {
        grid.add(Point(0, grid_height / grid_rows * i), Point(grid_width, grid_height / grid_rows * i));
    }
    //draw vertical lines
    for (int i = 0; i <= grid_collumns ; i ++ )
    {
        grid.add(Point(grid_width / grid_collumns * i, 0), Point(grid_width / grid_collumns * i, grid_height));
    }
    win.attach(grid);    
    win.wait_for_button();    
}


int main()
{
    try
    {
        drill_2();
    }
    catch (...)
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}