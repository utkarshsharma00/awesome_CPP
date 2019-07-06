#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void tarsum(vector<int> &arr, int target)
{
    vector<vector<bool>> storage(arr.size() + 1, vector<bool>(target + 1, false));
}

int main(int argc, char **argv)
{
    vector<int> arr{2, 5, 3, 1, 6};
    tarsum(arr, 9);
}
