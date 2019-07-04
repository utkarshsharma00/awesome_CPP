#include <iostream> //*Largest Increasing Subsequence
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void lis(vector<int> &arr)
{
    vector<int> strg(arr.size(), 1);

    //strg[0] = 0;
    for (int i = 1; i < strg.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                strg[i] = max(strg[i], strg[j] + 1);
            }
        }
    }
    
    int index = 0;

    for (int i = 0; i < strg.size(); i++)
    {
        //cout << strg[i] << " ";
        if (strg[index] < strg[i])
        {
            index = i;
        }
    }
}

int main(int argc, char** argv)
{
    vector<int> arr{10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
    lis(arr);
}
