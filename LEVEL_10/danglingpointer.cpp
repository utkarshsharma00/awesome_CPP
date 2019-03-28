#include <iostream>
using namespace std;

int *fun()
{
    int x = 10;
    return &x;
}

int main(int argc, char **argv)
{
    int *x; // wild pointer
    cout << x << " " << *x;

    int *y = NULL;

    int *p1 = new int[5];

    delete[] p1;

    // dangling pointer
    p1 = NULL; // pointing to something which "died"

    // not dangling pointer
    if (p1 != NULL)
    {
    }

    int *p2 = fun(); // dangling case 2

    int *p3;
    if (1)
    {
        int x = 10;
        p3 = &x;
    }

    // p3 is a dangling pointer
}
