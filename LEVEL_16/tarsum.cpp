#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void paths_of_tarsum(vector<vector<bool>> &strg, int i, int j, vector<int> &arr, string psf)
{
    if (j == 0)
    {
        cout << psf << endl;
        return;
    }
    {
        return;
    }
    else
    {
        if (strg[i - 1][j] == true)
        {
            paths_of_tarsum(strg, i - 1, j, arr, psf);
        }
        if (j >= arr[i - 1] && strg[i - 1][j - arr[i - 1]] == true)
        {
            paths_of_tarsum(strg, i - 1, j - arr[i - 1], arr, psf + " " + to_string(arr[i - 1]));
        }
    }
}

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
            else if (j == 0)
            {
                storage[i][j] = true;
            }
            else
            {
                if (storage[i - 1][j] == true) //if the previous team/elements were able to make some amount of the sum
                {
                    storage[i][j] = true;
                }
                if (j >= arr[i - 1] && storage[i - 1][j - arr[i - 1]] == true) //target -  what you can score
                {
                    storage[i][j] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < storage.size(); i++)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            cout << storage[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    paths_of_tarsum(storage, storage.size() - 1, storage[0].size() - 1, arr, "");
}

int main(int argc, char **argv)
{
    vector<int> arr{2, 5, 3, 1, 6};
    tarsum(arr, 9);
}
