#include <iostream>
#include <string>
#include <vector>
using namespace std;

void tarsum1(int arr[], int index, int target, string set, int size_of_array)
{
    if (index == size_of_array)
    {
        if (target == 0)
        {
            cout << set << " ";
            cout << endl;
        }
        return;
    }

    tarsum1(arr, index + 1, target - arr[index], set + to_string(arr[index]) + " ", size_of_array);
    tarsum1(arr, index + 1, target, set, size_of_array);
}

int main(int argc, char **argv)
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    string set1 = "";
    tarsum1(arr, 0, 70, set1, 7);
    cout << "-----------------------------" << endl;
    vector<int> set2;
    tarsum2(arr, 0, 70, set2, 7);
}
