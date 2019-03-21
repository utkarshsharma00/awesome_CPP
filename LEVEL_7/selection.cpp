#include <iostream>
using namespace std;

void swap(int arr[], int i, int j);

int main(int argc, char **argv)
{
    int arr[] = {11, 2, 44, 33, 7, 33};
    int n = sizeof(arr) / sizeof(int);

    for (int journey_counter = 1; journey_counter <= n - 1; journey_counter++)
    { //this for loop is for journey
        for (int i = journey_counter; i < n; i++)
        { //this for loop is for the number of comparisons
            if (arr[i] < arr[journey_counter - 1])
            {
                swap(arr, journey_counter - 1, i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}