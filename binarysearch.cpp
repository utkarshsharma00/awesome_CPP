#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[] = {20, 30, 40, 50, 60, 70, 80, 90};
    int find;
    cin >> find;
    int n = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (find > arr[middle])
        {
            low = middle + 1; //?
        }
        else if (find < arr[middle])
        {
            high = middle - 1; //?
        }
        else
        {
            //  middle=find; //?
            cout << "Data is present";
            break;
        }
    }
    cout << -1;
}