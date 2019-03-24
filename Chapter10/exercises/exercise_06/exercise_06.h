#include "../../stdlibfacilities.h"
#include <map>

class Roman_int
{
public:
    Roman_int();
    Roman_int(string roman_numeral);
    Roman_int(const Roman_int &);
    ~Roman_int();

    void operator=(const Roman_int &other);

    int asInt() const;
    string asNumeral() const;
    void assertSane() const;

private:
    string _numeral_value;
    int _int_value;
};

ostream& operator<<(ostream &out, const Roman_int &r);