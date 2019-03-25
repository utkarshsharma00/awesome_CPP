#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr_1[3][5] = {
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35}};

    int i, j = 0;
    int rows_1 = sizeof(arr_1) / sizeof(arr_1[0]); //for counting no of rows
    int cols_1 = sizeof(arr_1[0]) / sizeof(int);   //for counting no of cols

    for (j = 0; j < cols_1; j++)
    { //thinking about columns first in the above for loop
        if (j % 2 == 0)
        {
            for (i = 0; i < rows_1; i++)
            {
                cout << arr_1[i][j] << '\t';
            }
        }
        else
        {
            for (i = rows_1 - 1; i >= 0; i--)
            {
                cout << arr_1[i][j] << '\t';
            }
        }
    }
    //cout<<arr_1[i][j]<<'\t';
}