#include <iostream> //check this code for errors
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> value{60, 40, 100, 120};
    vector<int> weight{10, 40, 20, 30};

    cout << fractional_knapsack(value, weight, 50);
}
