#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[] = {2, 3, 7, -9, 6, 7, -20, 1, 2, 3, 11};
    int local_sum = arr[0];
    int global_sum = arr[0];
    int local_start = 0, local_end = 0;
    int global_start = 0, global_end = 0;

    int n = sizeof(arr) / sizeof(int);

    for (int i = 1; i < n; i++)
    {
        if (local_sum >= 0)
        {
            local_sum = local_sum + arr[i];
            local_end = i;
        }
        else
        {
            local_sum = arr[i];
            local_start = i;
            local_end = i;
        }
        if (local_sum > global_sum)
        {
            global_sum = local_sum;
            global_start = local_start;
            global_end = local_end;
        }
    }
    cout << global_sum << '\t' << global_start << "to" << global_end;
}