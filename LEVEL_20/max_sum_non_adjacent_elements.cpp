#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void max_sum_non_adjacent_elements(vector<int> &arr)
{
    int inclusive = arr[0];
    int exclusive = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int temp_inclusive = inclusive;
        int temp_exclusive = exclusive;

        inclusive = temp_exclusive + arr[i];
        exclusive = max(temp_inclusive, temp_exclusive);
    }

    cout << inclusive << " " << exclusive << endl;
}

int main(int argc, char **argv)
{
    vector<int> arr{5, 6, 10, 100, 10};
    max_sum_non_adjacent_elements(arr);
}
