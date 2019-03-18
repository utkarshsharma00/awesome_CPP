#include <iostream>
using namespace std;

void reverse(int arr[], int left, int right);
void swap(int arr[], int left, int right);

int main(int argc, char **argv)
{
    int arr[] = {2, 4, 7, 9, 1, 4};
    int n = sizeof(arr) / sizeof(int);

    int rotate = 3;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, rotate - 1);
    reverse(arr, rotate, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(int arr[], int left, int right)
{
    while (left < right)
    {
        swap(arr, left, right);
        left++;
        right--;
    }
}

void swap(int arr[], int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}