#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char **argv)
{
    int i;
    int arr[] = {50, 60, 70, 90, 2, 33, -14, 61};
    int min = INT_MAX; //Macros present in climits header file

    for (int i = 0; i < 8; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Min value is " << min;
}
