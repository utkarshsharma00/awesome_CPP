#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int train(vector<int> &arrival, vector<int> &departure)
{
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0; //for traversing arrival vector
    int j = 0; //for traversing departure vector
    
    while (i < arrival.size() && j < departure.size())
    {
        if (arrival[i] < departure[j])
        {
            i++;
            count++;
        }
        else
        {
            j++;
            count--;
        }

        if (count > max_train_standing)
        {
            max_train_standing = count;
        }
    }

    int min_platform_required = max_train_standing;

    return min_platform_required;
}

int main(int argc, char **argv)
{
    vector<int> arrival{900, 940, 950, 1100, 1500, 1800};
    vector<int> departure{910, 1200, 1120, 1130, 1900, 2000};

    cout << train(arrival, departure);
}
