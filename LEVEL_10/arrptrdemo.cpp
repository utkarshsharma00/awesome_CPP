#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int arr[4] = {10, 20, 30, 40};
    int *p1 = arr;     // when we write arr it simply means arr[0]
    int *p2 = &arr[0]; // this is basically same as p1
    int(*p3)[4] = &arr;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    p1++; //increases by 4
    p2++; //increases by 4
    p3++; //increases by 16 directly because it is a pointer to an array of integers whose size is 16bytes

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
}