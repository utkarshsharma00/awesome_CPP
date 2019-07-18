#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void countaibjck(string s)
{
    int counta = 0;
    int countb = 0;
    int countc = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            counta = 2 * counta + 1;
        }
        else if (s[i] == 'b')
        {
            countb = 2 * countb + counta;
        }
        else
        {
            countc = 2 * countc + countb;
        }
    }
    
    cout << countc << endl;
}

int main()
{
    countaibjck("abcabc");
}
