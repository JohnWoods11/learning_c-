#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>

Vector_ref<Image> make200x200Image(string image_file, Point py)
{
    Vector_ref<Image> image;
    Image *im = new Image(py, image_file);
    im->set_mask(Point(0,0), 200, 200);
    image.push_back(*im);
    return image;
}

Vector_ref<Rectangle> makeDiagonalRectangles(Point py, int width, int height, Color line, Color fill, int grid_x_max, int grid_y_max )
{
   
    Vector_ref<Rectangle> diagonal_rects;
    for (int i = 0; i * width < grid_x_max and i * height < grid_y_max ; i++)
    {
        diagonal_rects.push_back(new Rectangle (Point(py.x + i * width, py.y + i * height), width, height));
        diagonal_rects[i].set_color(line);
        diagonal_rects[i].set_fill_color(fill);
    }
    return diagonal_rects;
}



void drill_4()
{
    const Point py(50,50);
    Simple_window win(py, 1000, 800, "Drill 3");
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

    Vector_ref<Rectangle> diagonal_rects = makeDiagonalRectangles(Point(0,0), 100, 100, Color::red, Color::red, 800, 800);

    for (int i = 0; i < diagonal_rects.size(); i++)
    {
        win.attach(diagonal_rects[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        win.attach(make200x200Image("images.jpeg", Point(i*300%800, i *100%800))[0]);
    }

    win.wait_for_button();    
}


int main()
{
    try
    {
        drill_4();
    }
    catch (...)
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}