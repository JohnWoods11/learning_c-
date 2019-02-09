#include "../stdlibfacilities.h"

/** Prints the smallest, largest, mean and median of a set of doubles*/
class vector_analysis
{
private:
    /** Finds and sets the mean of a set of doubles*/
    void set_mean(const vector<double>&);
    /** Finds and sets the median of a set of doubles*/
    void set_median(const vector<double>&);
    /** Finds and sets the largest value in a set of doubles*/
    void set_largest(const vector<double>&);
    /** Finds and sets the smallest value in a set of doubles*/
    void set_smallest(const vector<double>&);
    /** Stores the mean*/
    double mean;
    /** Stores the median*/
    double median;
    /** Stores the smallest value*/
    double smallest;
    /** Stores the largest value*/
    double largest;
public:
    /** Print the results of vector analysis*/
    void print_results();
    /** Construct class and set variables*/
    vector_analysis(const vector<double>&);
    /** Class destructor*/
    ~vector_analysis();
};


vector_analysis::vector_analysis(const vector<double>& x)
{
    set_smallest(x);
    set_largest(x);
    set_mean(x);
    set_median(x);
}

vector_analysis::~vector_analysis()
{
}

void vector_analysis::set_mean(const vector<double>& x)
{
    double sum = 0;
    for (auto value:x)
    {
        sum += value;
    }
    mean = sum / x.size();
}

void vector_analysis::set_median(const vector<double>& x)
{
    vector<double> y = x;
    sort(y.begin(), y.end());
    if (y.size() % 2 == 0)
    {
        median = (y[y.size()/2 - 1] + y[y.size()/2]) / 2;
    }
    else
    {
        median = y[y.size() / 2];
    }
}

void vector_analysis::set_largest(const vector<double>& x)
{
    largest = x[1];
    for (auto value:x)
    {
        if (value > largest)
        {
            largest = value;
        }
    }
}

void vector_analysis::set_smallest(const vector<double>& x)
{
    smallest = x[1];
    for (auto value:x)
    {
        if (value < smallest)
        {
            smallest = value;
        }
    }
}

void vector_analysis::print_results()
{
    cout << "Analysis of floating-point number set: " << "Largest value = " << largest << endl << "Smallest value = " << smallest << endl
    << "Median = " << median << endl << "Mean =" << mean << endl << "Analysis complete." << endl;
}


int main()
{
    try
    {
        const vector<double> myvec {1, 2, 2, 5, 5, 6};
        vector_analysis analye(myvec);
        analye.print_results();
    }
    catch(const std::exception& e)
    {
        cout << "FATAL ERROR";
        return -1;    
    }
    return 0;
}





