#include <iostream>
#include <string>
#include <vector>

void equisets(int arr[], int index, string set1, int sum_of_set1, string set2, int sum_of_set2, size_of_array)
{
    if (index == size_of_array)
    {
        if (sum_of_set1 == sum_of_set2)
        {
            cout << "set1" << set1 << " "
                 << "set2" << set2;
        }
        return;
    }

    equisets(arr, index + 1, set1 + arr[index] + " ", sum_of_set1 + arr[index], set2, sum_of_set2, 7);
    equisets(arr, index + 1, set1, sum_of_set1, set2 + arr[index] + " ", sum_of_set2 + arr[index], 7);
}

int main(int argc, char **argv)
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    equisets(arr, 1, arr[0] + "", arr[0], "", 0, 7);
    // we are passing index from 1 because it helps us to split the tree and we dont get duplicate results. Also wrt index 1 we pass the set1 and sum_of_set1
    cout << "-----------------" << endl;
    equisetsv(arr, 1, arr[0] + "", arr[0], "", 0, 7);
}
