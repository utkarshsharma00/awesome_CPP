#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[] = {4, 2, 0, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    int inv[n];
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i]; //or can be simply done as inv[arr[i]] =i; this saves the memory created by temp
        inv[temp] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << inv[i];
    }
}