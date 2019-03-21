#include <iostream>
using namespace std;

void swap(int arr[], int i, int j);

int main(int argc, char **argv)
{
    int arr[] = {11, 2, 44, 33, 7, 33};
    int n = sizeof(arr) / sizeof(int);

    for (int journey_counter = 1; journey_counter <= n - 1; journey_counter++)
    { //this for loop is for journey
        for (int i = journey_counter; i > 0; i--)
        { //i not equal to zero because if we do that the code will burst because there is nothing to be compared with on the left side of the zeroth element.
            if (arr[i] < arr[i - 1])
            {
                swap(arr, i, i - 1);
            }
            else
            {
                break; //this is very necessary because it stops the extra number of comparisons
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