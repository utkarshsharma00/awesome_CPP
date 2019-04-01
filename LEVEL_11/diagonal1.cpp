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

    for (int gap = 0; gap < dim; gap++)
    {
        for (int i = 0, j = i + gap; j < dim; i++, j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}
