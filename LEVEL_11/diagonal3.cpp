#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[4][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}};

    int dim = 4;

    for (int gap = -dim + 1; gap <= 0; gap++)
    {
        for (int j = 0, i = j - gap; i < dim; i++, j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}