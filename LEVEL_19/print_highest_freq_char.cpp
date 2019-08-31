#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std:

void highest_freq(string s)
{
    unordered_map<char, int> freq_map;
    
    for (int i = 0; i < s.size(); i++)
    {
        freq_map[s[i]]++;
    }

    char ch;
    int max1 = 0;
    for (auto itr = freq_map.begin(); itr != freq_map.end(); itr++)
    {
        if (itr->second > max1)
        {
            max1 = itr->second;
            ch = itr->first;
        }
    }

    cout << ch << endl;
}
int main(int argc, char **argv)
{
    highest_freq("abbccddaccbdacdcba");
}
