#include "../../stdlibfacilities.h"

//include <iostream>

class Name_pairs
{
public:
    Name_pairs();
    Name_pairs(const Name_pairs &other);
    ~Name_pairs();

    Name_pairs& operator=(const Name_pairs &other);

    bool operator==(const Name_pairs &other) const;
    bool operator!=(const Name_pairs &other) const;
    
    string to_string() const;

    void read();
    void print() const;
    void sort();
    
    void assertSane() const;
    bool isEmpty() const;
private:
    void read_names();
    void read_ages();

    vector<string> name;
    vector<double> age;
    bool is_unique_name(string) const;
};

/*
std::ostream& operator<<(std::ostream &out, const Name_pairs &obj)
{

    return out;
}

Name_pairs operator+(Name_pairs lhs, Name_pairs rhs)
{
    return lhs + rhs;
}

((((std::cout << "hello") << "goodbye") << "one") << "two") << "three";

bool is_double(string);*/
