#include "../stdlibfacilities.h"

void f (const int i)
{
    int d = i + i;
    cout << i << endl;
    cout << i << " + " << i << " = " << d << endl;
}

int main()
{
    int a = 3;
    f(a);
    return 0;
}

// We can declare a non reference argument const. We would want to do that when passing an int or other standard size type on its own that we 
// don't want to be changed or want to signify that is it not going to be changed explicitly. 
// It means the function can not change the argument even though it is a copy of the actual argument. People don't do it often because they will
// ususaly want to change the variable they are passing by value or are passing something larger which would be better passed by reference
// to avoid needless copying.

