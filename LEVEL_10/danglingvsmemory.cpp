#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // memory leak
    // int* p = new int[5];
    // p = new int[10];

    int *p = new int[5];
    delete[] p;
    // what is p now? dangling -> pointing to a heap location which has been released
    p = NULL; // no longer dangling

    //-------------------------------------------------------------------
    if (1)
    {
        int x = 10;
        p = &x;
    }

    // p is dangling

    //--------------------------------------------------------------------
    int *x; // wild pointer
    cout << x << " " << *x;

    int *y = NULL; // wild pointer
}