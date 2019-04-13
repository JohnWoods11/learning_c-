#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "GUI/std_lib_facilities.h"
#include <iostream>


Vector_ref<Textbox> make_class_boxes()
{
    Vector_ref<Textbox> boxes;

    boxes.push_back( new Textbox (Box(Point(50,50), 70, 20, 10), "Window"));
    boxes.push_back( new Textbox (Box(Point(200,50), 80, 20, 10), "Line_style"));
    boxes.push_back( new Textbox (Box(Point(350,50), 50, 20, 10), "Color"));
    boxes.push_back( new Textbox (Box(Point(50,150), 120, 20, 10), "Simple_window"));
    boxes.push_back( new Textbox (Box(Point(230,130), 60, 20, 10), "Shape"));                          
    boxes.push_back( new Textbox (Box(Point(340,150), 50, 20, 10), "Point"));                          
    boxes.push_back( new Textbox (Box(Point(30,220), 40, 20, 10), "Line"));                           
    boxes.push_back( new Textbox (Box(Point(80,220), 45, 20, 10), "Lines"));                          
    boxes.push_back( new Textbox (Box(Point(135,220), 65, 20, 10), "Polygon"));
    boxes.push_back( new Textbox (Box(Point(210,220), 40, 20, 10), "Axis"));
    boxes.push_back( new Textbox (Box(Point(260,220), 80, 20, 10), "Rectangle"));
    boxes.push_back( new Textbox (Box(Point(350,220), 40, 20, 10), "Text"));
    boxes.push_back( new Textbox (Box(Point(400,220), 50, 20, 10), "Image"));

    return boxes;
}

void draw_boxes(Simple_window &win, Vector_ref<Textbox> &boxes)
{
    for (int i = 0; i < boxes.size(); i++)
    {
        win.attach(boxes[i]);
    }
}

Vector_ref<Arrow> make_class_arrows()
{
    Vector_ref<Arrow> arrows;

    arrows.push_back( new Arrow(Point(85,70), Point(110, 150)));
    arrows.push_back( new Arrow(Point(230,150), Point(50,220)));
    arrows.push_back( new Arrow(Point(240,150), Point(102,220)));
    arrows.push_back( new Arrow(Point(250,150), Point(167,220)));
    arrows.push_back( new Arrow(Point(260,150), Point(230,220)));
    arrows.push_back( new Arrow(Point(270,150), Point(300,220)));
    arrows.push_back( new Arrow(Point(275,150), Point(370,220)));
    arrows.push_back( new Arrow(Point(280,150), Point(425,220)));

    return arrows;
}

void draw_arrows(Simple_window &win, Vector_ref<Arrow> &arrows)
{
      for (int i = 0; i < arrows.size(); i++)
    {
        win.attach(arrows[i]);
    }
}


void exercisse_6()
{
    Simple_window win(Point(50,50), 600, 400, "Exercise 6");
    
    Vector_ref<Textbox> boxes = make_class_boxes();
    Vector_ref<Arrow> arrows = make_class_arrows();

    draw_boxes(win,boxes);
    draw_arrows(win,arrows);

    win.wait_for_button();
}


int main()
{
    try 
    {
        exercisse_6();
    }
    catch (...)
    {
        cout << "MAJOR ERROR!";
        return -1;
    }
    return 0;
}