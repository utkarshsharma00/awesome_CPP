#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void matrix_chain_multiplication(vector<int> &matrix_arr)
{
    vector<vector<int>> storage(matrix_arr.size(), vector<int>(matrix_arr.size() - 1));
    for (int gap = 0; gap < matrix_arr.size(); gap++)
    {
        for (int i = 0, j = i + gap; j < storage.size(); i++, j++)
        {
            if (gap == 0)
            {
                storage[i][j] = 0;
            }
            else if (gap == 1)
            {
                if (matrix_arr[i] == matrix_arr[j])
                {
                    storage[i][j] = 0;
                }
                else
                {
                    storage[i][j] = matrix_arr[i] * matrix_arr[j] * matrix_arr[j + 1];
                }
            }
}

int main(int argc, char **argv)
{
    vector<int> matrix_arr{10, 20, 30, 40, 50, 60};
    matrix_chain_multiplication(matrix_arr);
}
