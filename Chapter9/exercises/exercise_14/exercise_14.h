#include "../../stdlibfacilities.h"

class Money
{
public:
    Money();
    Money(int);
    Money(const Money&);
    ~Money();
    void operator=(const Money&);
    long int dollars() const;
    long int cents() const;

    bool assertSane() const;

    Money operator+(const Money&);
    Money operator-(const Money&);  
    Money operator*(const double);
    

private:
    long int _cents;
};

ostream& operator<<(ostream&, const Money&);
istream& operator>>(istream&, Money&);