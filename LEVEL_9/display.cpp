#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[2][3] = {
        {11, 13, 14},
        {21, 22, 23}};

    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(int);

    cout << rows;
    cout << cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}