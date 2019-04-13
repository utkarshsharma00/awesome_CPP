#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    equisets(arr, 1, arr[0] + "", arr[0], "", 0, 7);
    // we are passing index from 1 because it helps us to split the tree and we dont get duplicate results. Also wrt index 1 we pass the set1 and sum_of_set1
    cout << "-----------------" << endl;
    equisetsv(arr, 1, arr[0] + "", arr[0], "", 0, 7);
}
