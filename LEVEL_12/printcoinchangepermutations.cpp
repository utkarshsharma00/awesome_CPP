#include <iostream> //this is basically 'staircase' type question
#include <string>

using namespace std;

void print_coin_change_permutations(int arr[], int size_of_array, int sum, string as_of_now)
{
    if (sum == 0)
    {
        cout << as_of_now<<endl;
        return;
    }
    
    for (int i = 0; i < size_of_array; i++)
    {
        if (arr[i] <= sum)
        {
            print_coin_change_permutations(arr, size_of_array, sum - arr[i], as_of_now + to_string(arr[i]));
        }
    }
}

int main(int argc, char **argv)
{
    int arr[]={2,3,5};
    print_coin_change_permutations(arr, 3, 7, "");
}