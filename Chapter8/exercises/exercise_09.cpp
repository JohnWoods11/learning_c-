#include "../stdlibfacilities.h"

/**Computes index that is the sum of all price/weight pairs, returns index as vector*/
vector<double> index_weight_price_pairs(vector<double>& weights, vector<double>&prices)
{
    if (weights.size() != prices.size())
    {
        throw invalid_argument("the weight and price vectors must be the same size.");
    }
    vector<double> index;
    for (int i = 0; i < weights.size(); i++)
    {
        index.push_back(weights[i]*prices[i]);
    }
    return index;
}

int main()
{
    try
    {
        vector<double> weights {3.2, 3.3, 1, 8, 0.2};
        vector<double> prices {2.99, 5, 6.80, 9.99, 11.00};
        vector<double> index = index_weight_price_pairs(weights, prices); 
        for (auto value:index)
        {
            cout << "£" << value << endl;
        }     
    }
    catch(const std::exception& e)
    {
        cout << "Error" << e.what();
        return -1;
    }
    return 0;
}