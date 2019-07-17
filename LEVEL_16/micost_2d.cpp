#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int mincost(vector<vector<int>> &cost)
{
    vector<vector<int>> strg(cost.size(), vector<int>(cost[0].size(), 0));

}

int main(int argc, char **argv)
{
    vector<vector<int>> cost{{2, 6, 5, 1, 3, 4},
                             {0, 4, 9, 2, 9, 0},
                             {4, 8, 1, 0, 6, 5},
                             {0, 3, 3, 1, 5, 4},
                             {1, 2, 7, 0, 6, 9},
                             {5, 7, 1, 3, 8, 2}};

    cout << mincost(cost);
}
