#include <iostream>
using namespace std;

void fun(int arr[])
{
    int len = sizeof(arr) / sizeof(int);
    cout << len << endl;
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

int main(int argc, char **argv)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int len = sizeof(arr) / sizeof(int);
    cout << len << endl;
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "--------------------------------";
    fun(arr);
}
