#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[] = {10, 10, 10, 20, 20, 20, 20, 20, 20, 30, 30, 30};
    int find;
    cin >> find;
    int n = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (find > arr[middle])
        {
            low = middle + 1;
        }
        else if (find < arr[middle])
        {
            high = middle - 1;
        }
        else
        {
            // middle=find;
            high = middle - 1;
            ans = middle;
            middle = (low + high) / 2;
        }
    }
    cout << ans;
}

//{10,20,20,20,30,30,30,40,50,50,50}