#include <iostream>
using namespace std;
void swap(int arr[], int i, int j);
int main(int argc, char **argv)
{
    int arr[] = {11, 55, 33, 22, 100};
    int n = sizeof(arr) / sizeof(int);

    for (int journey_counter = 1; journey_counter <= n - 1; journey_counter++)
    { //this for loop is for journey
        for (int i = 0; i < n - journey_counter; i++)
        { //this for loop is for the number of comparisons
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
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