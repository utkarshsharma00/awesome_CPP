#include <iostream> //check this code for errors
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

class Items
{
public:
    int weight;
    int value;
    double ratio;

    Items(int weight, int value)
    {
        this->weight = weight;
        this->value = value;
        this->ratio = value * 1.0 / weight;
    }

    bool operator<(const Items &other) const
    {
        return this->ratio < other.ratio;
    }
};

int fractional_knapsack(vector<int> &value, vector<int> &weight, int capacity)
{
    //yet to be written
}

int main(int argc, char **argv)
{
    vector<int> value{60, 40, 100, 120};
    vector<int> weight{10, 40, 20, 30};

    cout << fractional_knapsack(value, weight, 50);
}
