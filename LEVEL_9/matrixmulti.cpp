#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr_1[2][3] = {
        {11, 13, 14},
        {21, 22, 23}};

    int arr_2[3][2] = {
        {0, 2},
        {1, 7},
        {2, 5}};

    int rows_1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int cols_1 = sizeof(arr_1[0]) / sizeof(int);

    int rows_2 = sizeof(arr_2) / sizeof(arr_2[0]);
    int cols_2 = sizeof(arr_2[0]) / sizeof(int);

    int arr_3[rows_1][cols_2];
    if (cols_1 != rows_2)
    {
        cout << "Error";
    }

    else
    {
        for (int i = 0; i < rows_1; i++)
        {
            for (int j = 0; j < cols_2; j++)
            {
                //0
                arr_3[i][j] = 0;                 // should be assigned zero otherwise it will have Garbage value
                for (int k = 0; k < rows_2; k++) // or k can also be less the cols_1 (k is actually used for multiplication)
                {
                    arr_3[i][j] += arr_1[i][k] * arr_2[k][j];
                }
            }
        }
    }

    for (int l = 0; l < rows_1; l++)
    {
        for (int q = 0; q < cols_2; q++)
        {
            cout << arr_3[l][q] << '\t';
        }
        cout << endl;
    }
}