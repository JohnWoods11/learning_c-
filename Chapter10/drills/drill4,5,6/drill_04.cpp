#include "drill_04.h"

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
   ofstream ost {"mydata.txt"};
   for (auto point:original_points)
   {
      ost << point << endl;
   }
   ifstream ist {"mydata.txt"};
   Point p;
   vector<Point> processed_points;
   while (ist >> p)
   {
       processed_points.push_back(p);
   }
   cout << "Original:" << endl;
   for (auto point:original_points)
   {
       cout << point << endl;
   }
   cout << "Processed:" << endl;
   for (auto point:processed_points)
   {
       cout << point << endl;
   }
   if (processed_points.size() != original_points.size())
   {
       cout << "Something's wrong!" << endl;
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