#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void CoinChange_Perm(vector<int> &arr, int target) //target is the amount that has to be achieved
{
    vector<int> strg(target + 1, false);
    strg[0] = 1;
    for (int i = 0; i < strg.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            int previous = i - arr[j];
            int temp = 0;
            if (previous >= 0)
            {
                temp = strg[previous];
            }
            strg[i] += temp;
        }
    }
}

void CoinChange_Comb(vector<int> &arr, int target)
{
    vector<int> strg(target + 1, false);
    strg[0] = 1;
    //yet to be written
}

int main(int argc, char **argv)
{
    vector<int> arr{2, 3, 5, 6};
    CoinChange_Perm(arr, 7);
    cout << endl;
    CoinChange_Comb(arr, 7);
}
