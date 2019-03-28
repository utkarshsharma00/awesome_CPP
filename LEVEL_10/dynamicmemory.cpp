#include <iostream>
using namespace std;
const int sz = 100;

int *wrong_function()
{
    int arr[sz];

    for (int i = 0; i < sz; i++)
    {
        arr[i] = i;
    }
    return arr;
}
int main()
{
    int *p = wrong_function();

    for (int i = 0; i < sz; i++)
    { // this loop is of no importance because once we have returned the arr in the wrong_function the memory space occupied by the arr has been destroyed. Therefore a warning will be there. To solve this we can use static in declaration of the int arr[sz] or new or can make it global
        cout << *(p + i) << endl;
    }
}