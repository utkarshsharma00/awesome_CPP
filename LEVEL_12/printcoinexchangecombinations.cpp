#include <iostream>
#include <string>

using namespace std;

void print_coin_change_combinations(int arr[], int last_used_coin_index, int size_of_array, int sum, string as_of_now)
{
    if (sum == 0)
    {
        cout << as_of_now << endl;
        return;
    }
    if (sum < 0)
    {
        return;
    }
    for (int i = last_used_coin_index; i < size_of_array; i++) //not added 1 to last_used... in i variable because the no can be used simultaneoulsy example 225 ,whereas in queen problem the same queen cannot be repeated.
    {
        print_coin_change_combinations(arr, i, size_of_array, sum - arr[i], as_of_now + to_string(arr[i]));
    }
}

int main(int argc, char **argv)
{
    int arr[] = {2, 3, 5};
    print_coin_change_combinations(arr, 0, 3, 7, "");
}