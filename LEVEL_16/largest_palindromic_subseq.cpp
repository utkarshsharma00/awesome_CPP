#include <iostream>
#include <vector>
#include <string>

using namespace std;

void LPS(string s1)
{
    vector<vector<int>> storage(s1.length(), vector<int>(s1.length()));

    for (int gap = 0; gap < s1.size(); gap++)
    {
        for (int i = 0, j = i + gap; j < storage.size(); i++, j++)
        {
            if (gap == 0)
            {
                storage[i][j] = 1;
            }
            else if (gap == 1)
            {
                if (s1[i] == s1[j])
                {
                    storage[i][j] = 2;
                }

                else
                {
                    storage[i][j] = 1;
                }
            }
}

int main()
{
    LPS("abkccgbc");
}
