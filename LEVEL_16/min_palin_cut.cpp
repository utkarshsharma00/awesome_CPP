#include <iostream> // Tough question in DP, will definitely be asked somewhere
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void minimum_palin_cut(string s)
{
    vector<vector<int>> storage(s.length(), vector<int>(s.length()));
    for (int gap = 0; gap < s.size(); gap++)
    {
        for (int i = 0, j = i + gap; j < storage.size(); i++, j++)
        {
            if (gap == 0)
            {
                storage[i][j] = 0;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    storage[i][j] = 0;
                }
                else
                {
                    storage[i][j] = 1;
                }
            }
    
}

int main(int argc, char **argv)
{
    minimum_palin_cut("abccbc");
}
