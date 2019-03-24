//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>

using namespace std;

inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void keep_window_open(string s)
{
	if (s=="") return;
	cin.clear();
	cin.ignore(120,'\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss!=s)
			cout << "Please enter " << s << " to exit\n";
		return;
    }
}

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}
//------------------------------------------------------------------------------

template <typename Target, typename Source>
Target narrow_cast(Source src)
{
    Target tgt = src;

    if ((Source)tgt != src)
        error("Invalid narrowing conversion");

    return tgt;
}

template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}