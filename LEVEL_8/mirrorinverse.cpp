#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[] = {4, 2, 0, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i, n; i++)
    {
        int temp = arr[i]; //or can be understood as arr[arr[i]] = i;
        if (arr[temp] != i)
        {
            cout << "Its not inverse" << endl;
            return -1;
        }
    }
    cout << "It is inverse\n";
}