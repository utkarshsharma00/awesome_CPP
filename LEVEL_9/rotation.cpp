#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(int);

    for (int i = 0; i < rows; i++) //transpose
    {
        for (int j = i; j < cols; j++)
        {
            int temp = arr[j][i];
            arr[j][i] = arr[i][j];
            arr[i][j] = temp;
        }
    }

    for (int i = 0; i < 4; i++)
    { //for reverse
        int left = 0;
        int right = 3; //this statement is hardcoded !
        while (left < right)
        {
            int temp = arr[i][left];
            arr[i][left] = arr[i][right];
            arr[i][right] = temp;
            left++;
            right--;
        }
    }
    for (int i = 0; i < rows; i++)//for printing the answer
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
}
