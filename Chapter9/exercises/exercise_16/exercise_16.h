#include "../../stdlibfacilities.h"
#include <map>
#include <cmath>
#include <algorithm>

enum class Currency
{
    USD = 0, DSK = 1, GBP = 2, JPY = 3
};

std::string currency_to_string(Currency c);
Currency string_to_currency(const std::string &s);

class Money
{
public:
    Money();
    Money(int, Currency);
    Money(const Money&);
    ~Money();

    void operator=(const Money&);
    long int standardDenominator() const;
    long int fractionalDenominator() const;
    Currency currency() const;

    bool isSane() const;
    bool isSameCurrency() const;

    void assertSameCurrency(const Money &other) const;
    void assertSane() const;

    Money operator+(const Money&);
    Money operator-(const Money&);  
    Money operator*(const double);
    

private:
    Currency _currency;
    long int _base_denominator;
};

istream& operator>>(istream& in, Currency &c);                  // in hindsight i should have made a currency output operator
ostream& operator<<(ostream&, const Money&);
istream& operator>>(istream&, Money&);