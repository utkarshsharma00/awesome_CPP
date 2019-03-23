#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < (1 << n); i++)
    {
        for (int b = n - 1, array_index = 0; b >= 0; b--, array_index++)
        {
            int bm = 1 << b;
            if ((i & bm) == bm)
            {
                cout << arr[array_index] << " ";
            }
            else
            {
                cout << " _ "
                     << " ";
            }
        }

        cout << endl;
    }
}