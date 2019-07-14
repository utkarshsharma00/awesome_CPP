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
            else
            {
                if (s[i] == s[j] && storage[i + 1][j - 1] == 0) //s[i] and s[j] indicate the start and end points
                {
                    storage[i][j] = 0;
                }
                else
                {
                    int mymin = s.size();
                    for (int k = 0; k < gap; k++)
                    {
                        int lhs = storage[i][j - gap + k]; //this is basically the start point
                        int rhs = storage[i + 1 + k][j];
                        mymin = min(lhs + rhs, mymin);
                    }

                    storage[i][j] = mymin + 1;
                }
            }
        }
    }   
    
}

int main(int argc, char **argv)
{
    minimum_palin_cut("abccbc");
}
