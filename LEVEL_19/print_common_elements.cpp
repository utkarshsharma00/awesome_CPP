#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void print_common_elements1(vector<int> &one, vector<int> &two)
{
    unordered_map<int, int> map;
    
    for (int i = 0; i < one.size(); i++)
    {
        map[one[i]]++;
    }

    vector<int> pce1;
    for (int i = 0; i < two.size(); i++)
    {
        if (map.find(two[i]) != map.end())
        {
            pce1.push_back(two[i]);
            map.erase(two[i]);
        }
    }
    //yet to be written
}

void print_common_elements2(vector<int> &one, vector<int> &two)
{
    unordered_map<int, int> map;
    
    for (int i = 0; i < one.size(); i++)
    {
        map[one[i]]++; 
    }

    for (int i = 0; i < two.size(); i++)
    {
        if (map.count(two[i]) == 1 && map[two[i]] > 0)
        {
            cout << two[i] << " ";
            map[two[i]]--;
        }
    }
    //yet to be written
}

int main(int argc, char **argv)
{
    vector<int> one{2, 1, 5, 1, 3, 2, 1};
    vector<int> two{4, 5, 2, 1, 2, 1, 2};
    print_common_elements1(one, two);
    cout << endl;
    print_common_elements2(one, two);
}
