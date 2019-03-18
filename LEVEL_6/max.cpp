#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char **argv)
{
    int i;
    int arr[] = {50, 60, 70, 90, 2, 33, -14, 61};
    int max = INT_MIN; //Macros present in climits header file

    for (int i = 0; i < 8; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Max value is " << max;
}