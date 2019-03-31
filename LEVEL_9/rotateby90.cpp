#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[4][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44},
    };

    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
        {
            int t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int l = 0;
        int r = 3;
        while (l < r)
        {
            int t = arr[i][l];
            arr[i][l] = arr[i][r];
            arr[i][r] = t;

            l++;
            r--;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}