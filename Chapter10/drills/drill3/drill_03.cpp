#include "drill_03.h"

void f()
{
   cout << "Please enter 7 (x,y) pairs in the format (x,y):";
   vector<Point> original_points;
   for (int i = 0; i < 7; i++)
   {
       Point p;
       cin >> p;
       original_points.push_back(p);
   }
   for (auto point:original_points)
   {
       cout << point.x() << ',' << point.y() << endl;
   }
}

int main()
{
    try
    {
        f();
    }
    catch(...)
    {
        cout << "unforseen error." << endl;
    }
    
}