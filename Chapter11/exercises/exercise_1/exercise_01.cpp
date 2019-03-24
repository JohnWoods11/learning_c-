#include "exercise_01.h"

void f()
{
    lowerFile("input.txt", "output.txt");
}



int main()
{
    try
    {
        f();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    return 0;    
}