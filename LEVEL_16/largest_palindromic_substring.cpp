#include <iostream>  
#include <vector>
#include <string>

using namespace std;

int length = 0;
void largest_palin_substring(string s)
{
    vector<vector<bool>> storage(s.length(), vector<bool>(s.length()));

    for (int gap = 0; gap < s.size(); gap++)
    {
        for (int i = 0, j = i + gap; j < storage.size(); i++, j++)
        {
            if (gap == 0)
            {
                storage[i][j] = 1;
            }
}

int main()
{
    largest_palin_substring("abccbc");
}
