#include <iostream>
using namespace std;

void swap(int arr[], int left, int right);

int main(int argc, char **argv)
{
    int arr[] = {2, 5, 7, 9, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        swap(arr, left, right);
        left++;
        right--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}