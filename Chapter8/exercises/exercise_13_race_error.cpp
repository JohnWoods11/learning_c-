#include "../stdlibfacilities.h"

/** Analyses a set of strings by string length and lexicographic position*/ 
class string_analysis
{
private:
    /** Creates a set of integers corresponding to the string lengths of the set of strings*/
    vector<int> set_string_lengths(const vector<string>&);
    /** Sets the value of the longest string*/
    void set_longest(const vector<string>&, const vector<int>&);
    /** Sets the value of the shortest string*/
    void set_shortest(const vector<string>&, const vector<int>&);
    /** Sets the lexicographically first and last string*/
    void set_lexicographic_first_and_last(const vector<string>&);
    /** Holds the longest string*/
    string longest;
    /** Holds the shortest string*/
    string shortest;
    /** Holds the lexicographically first string*/
    string lexicographic_first;
    /** Holds the lexicographically last string*/
    string lexicographic_last;
public:
    /** Calls all the analysis functions*/
    void analyse(const vector<string>&);
    /** Prints the results of analysis*/
    void print_results();
    /** Class constructor*/
    string_analysis();
    /** Class destructor*/
    ~string_analysis();
};

string_analysis::string_analysis()
{}

string_analysis::~string_analysis()
{}

vector<int> string_analysis::set_string_lengths(const vector<string>& strings)
{
    vector<int> lengths;
    for (auto value: strings)
    {
        lengths.push_back(value.size());
    }
    return lengths;
}

void string_analysis::set_longest(const vector<string>& strings, const vector<int>& lengths)
{
    int longest_position;
    for (int i = 0; i < lengths.size(); i++)
    {
        if (lengths[i] > lengths[longest_position])
            {
                longest_position = i;
            }
    }
    longest = strings[longest_position];
}

void string_analysis::set_shortest(const vector<string>& strings, const vector<int>& lengths)
{
    int shortest_position;
    for (int i = 0; i < lengths.size();i++)
    {
        if (lengths[i] < lengths[shortest_position])
        {
            shortest_position = i;
        }
    }
    shortest = strings[shortest_position];
}

void string_analysis::set_lexicographic_first_and_last(const vector<string>& strings)
{
    vector<string> sorted_strings = strings;
    sort(sorted_strings.begin(), sorted_strings.end());
    lexicographic_first = sorted_strings[0];
    lexicographic_last = sorted_strings[sorted_strings.size() - 1];
}

void string_analysis::analyse(const vector<string>& strings)
{ 
    const vector<int> lengths = set_string_lengths(strings);
    set_longest(strings, lengths);
    set_shortest(strings, lengths);
    set_lexicographic_first_and_last(strings);
}

void string_analysis::print_results()
{
    cout << "String analysis:" << endl << "Shortest string: " << shortest << endl << "Longest string: " << longest << endl <<
    "Lexicographically first string: " << lexicographic_first << endl << "Lexicographically last string: " << lexicographic_last <<
    endl << "End of string analysis." << endl;
}

int main()
{
    try
    {
        string_analysis analyser;
        const vector<string> words {"many", "different", "words", "all", "in", "one", "vector"};
        analyser.analyse(words);
        analyser.print_results();
    }
    catch(...)
    {
        cout << "Termination error.";
        return -1;
    }
    return 0;
}
