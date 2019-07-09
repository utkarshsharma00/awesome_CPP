#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void tarsum(vector<int> &arr, int target)
{
    vector<vector<bool>> storage(arr.size() + 1, vector<bool>(target + 1, false));
    for (int i = 0; i < storage.size(); i++)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            if (i == 0 && j == 0) //To Put All true in the first col
            {
                storage[i][j] = true;
            }
            else if (i == 0) //To Put All false in the first row
            {
                storage[i][j] = false;
            }
}

int main(int argc, char **argv)
{
    vector<int> arr{2, 5, 3, 1, 6};
    tarsum(arr, 9);
}
