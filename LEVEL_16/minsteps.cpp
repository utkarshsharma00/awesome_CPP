#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int countMinSteps(vector<int> &jumpSize)
{
    vector<int> strg(jumpSize.size(), 0);
    strg[0] = 0;
}

int main()
{
    vector<int> jumpSize{0, 2, 3, 2, 0, 2, 0, 2, 4};
    cout << countMinSteps(jumpSize) << endl;
}
