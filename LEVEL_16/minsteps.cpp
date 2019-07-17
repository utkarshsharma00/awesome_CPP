#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    vector<int> jumpSize{0, 2, 3, 2, 0, 2, 0, 2, 4};
    cout << countMinSteps(jumpSize) << endl;
}
