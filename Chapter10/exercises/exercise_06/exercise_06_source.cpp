#include "exercise_06.h"


/** numeral value to integer value map*/
map <char, int> Numeralnumber =
    {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}};


/** Returns the integer value of a roman numeral*/
static int toInt(int position, const string numeral, int seen_before, int proceeding_lowers) 
{
    if (seen_before > 2 or proceeding_lowers > 1 or seen_before > 0 and proceeding_lowers > 0)
    {
        throw out_of_range(numeral + " is invalid");
    }
    else if (position == numeral.size() - 1)
    {
        return Numeralnumber.at(numeral[position]);
    }
    else if (Numeralnumber.at(numeral[position]) == Numeralnumber.at(numeral[position + 1]))
    {
        return Numeralnumber.at(numeral[position]) + toInt(position + 1, numeral, seen_before + 1, proceeding_lowers);
    }
    else if (Numeralnumber.at(numeral[position]) > Numeralnumber.at(numeral[position + 1]))
    {
        return Numeralnumber.at(numeral[position]) + toInt(position + 1, numeral, 0, 0);
    }
    else if (Numeralnumber.at(numeral[position]) < Numeralnumber.at(numeral[position + 1]))
    {
        return toInt(position + 1, numeral, seen_before, proceeding_lowers + 1) - Numeralnumber.at(numeral[position]);
    }
}



/** Default constructor empty roman numeral*/
Roman_int::Roman_int()
:_numeral_value(" "), _int_value(0)
{
    assertSane();
}

/** Constructor for roman numeral with value*/
Roman_int::Roman_int(string n)
: _numeral_value(n), _int_value(toInt(0, n, 0, 0))
{
    assertSane();
}

/** Copy constructir for roman numeral*/
Roman_int::Roman_int(const Roman_int &other)
:_numeral_value(other._numeral_value), _int_value(other._int_value)
{
    assertSane();
}

/** Destructor for roman numeral*/
Roman_int::~Roman_int()
{
    assertSane();
}

/** Copy assignment operator for roman numeral*/
void Roman_int::operator=(const Roman_int &other)
{
    this -> _numeral_value = other._numeral_value;
    this -> _int_value = other._int_value;
}

/** Asserts roman numeral is valid*/
void Roman_int::assertSane() const
{
    for (auto letter:_numeral_value)
    {
        if (!Numeralnumber.count(letter))
        {
            throw out_of_range(_numeral_value + " is not an accepted roman numeral");
        }
    }
}

/** returns the objects integer value*/
int Roman_int::asInt() const
{
    return _int_value;
}


/** returns the objects roman numeral string*/
string Roman_int::asNumeral() const
{
    return _numeral_value;
}

/** Output operator for a Roman_int*/
ostream& operator<<(ostream &out, const Roman_int &r)
{
    out << r.asNumeral();
    return out;
}