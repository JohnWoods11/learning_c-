#include "../stdlibfacilities.h"

namespace_x.h
///
class X{ public: X(); int get_val(); int print(); void set_val(); private: int _x; };
///

int main(){ X::get_val(); X::print(); }

namespace_x.cpp
///
namespace X
{
namespace detail{ int _x; }

int get_val(){ return detail::_x;} 
void set_val(int x){ detail::_x = x; }
void print()
{
    cout << get_val() << endl;
}
}
///

namespace Y
{
    int var;
    void print()
    {
        cout << var << endl;
    }
}

namespace Z
{
    int var;
    void print()
    {
        cout << var << endl;
    }
}


int main()
{
    X::var = 7;
    X::print();
    using namespace Y;
    var = 9;
    print();
    {
        using Z::var;
        using Z::print;
        var = 11;
        print();
    }
    print();
    X::print();
}
