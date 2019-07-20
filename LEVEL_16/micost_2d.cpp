#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void mincostPath(vector<vector<int>> &strg, int row, int col, string path_so_far)
{
    if (row == strg.size() - 1 && col == strg[0].size() - 1)
    {
        cout << path_so_far << endl;
        return;
    }
    else if (row == strg.size() - 1)
    {
        mincostPath(strg, row, col + 1, path_so_far + "h");
    }
    else if (col == strg[0].size() - 1)
    {
        mincostPath(strg, row + 1, col, path_so_far + "v");
    }
    else
    {
        int mymin = min(strg[row][col + 1], strg[row + 1][col]);
        if (strg[row + 1][col] == mymin)
        {
            mincostPath(strg, row + 1, col, path_so_far + "v");
        }

        if (strg[row][col + 1] == mymin)
        {
            mincostPath(strg, row, col + 1, path_so_far + "h");
        }
    }
}

int mincost(vector<vector<int>> &cost)
{
    vector<vector<int>> strg(cost.size(), vector<int>(cost[0].size(), 0));  
    
    for (int i = cost.size() - 1; i >= 0; i--)
    {
        for (int j = cost[0].size() - 1; j >= 0; j--)
        {
            if (i == cost.size() - 1 && j == cost[0].size() - 1)
            {
                strg[i][j] = cost[i][j];
            }
            else if (i == cost.size() - 1)
            {
                strg[i][j] = cost[i][j] + strg[i][j + 1];
            }
            else if (j == cost.size() - 1)
            {
                strg[i][j] = cost[i][j] + strg[i + 1][j];
            }
            else
            {
                strg[i][j] = cost[i][j] + min(strg[i][j + 1], strg[i + 1][j]);
            }
        }
    }
    
    mincostPath(strg, 0, 0, " ");
    return strg[0][0];
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
