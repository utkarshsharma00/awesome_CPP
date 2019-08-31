#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void longest_subseq_of_consecutive_elements(vector<int> &arr)
{
    unordered_map<int, bool> map;
    
    for (int i = 0; i < arr.size(); i++)
    {
        map[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (map.find(arr[i] - 1) == map.end())
        {
            map[arr[i]] = true;
        }
        else
        {
            map[arr[i]] == false;
        }
    }
    
    int overall_start = 0;
    int overall_len = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (map[arr[i]] == true)
        {
            int total_start = arr[i];
            int total_len = 1;
            
            //yet to be written
        }    

    }

    cout << overall_start << "\t" << overall_len << endl;
}

int main(int argc, char **argv)
{
    vector<int> arr{11, 3, 5, 9, 12, 2, 6, 8, 1, 10, 15, 25, 20, 16};
    longest_subseq_of_consecutive_elements(arr);
}
