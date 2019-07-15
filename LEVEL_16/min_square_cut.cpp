#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int min_square_cut(vector<vector<int>> &arr, int length, int breadth)
{
    if (length == 0 || breadth == 0)
    {
        return 0;
    }
    if (length == breadth)
    {
        return 1;
    }

    if (arr[length][breadth] != 0)
    {
        return arr[length][breadth];
    }
}

int main(int argc, char **argv)
{
    int length = 36;
    int breadth = 30;
    vector<vector<int>> arr(length + 1, vector<int>(breadth + 1, 0));

    cout << min_square_cut(arr, length, breadth);
}
