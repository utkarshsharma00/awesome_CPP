#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[4][4] = {
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 1, 0}};

    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(int);
    int i = 0;         // for row traversal
    int j = 0;         // for cols traversal
    int direction = 0; // eswn (0123)

    while (true)
    {
        direction = (direction + arr[i][j]) % 4; // this elegant piece of line saves several if and else

        if (direction == 0)
        {
            if (j < cols - 1)
            {
                j++;
            }
            else
            {
                break;
            }
        }
        else if (direction == 1)
        {
            if (i < rows - 1)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        else if (direction == 2)
        {
            if (j > 0)
            {
                j--;
            }
            else
            {
                break;
            }
        }
        else if (direction == 3)
        {
            if (i > 0)
            {
                i--;
            }
            else
            {
                break;
            }
        }
    }
    cout << i << " " << j;
}
