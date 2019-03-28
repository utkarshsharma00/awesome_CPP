#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
    int *p = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p[i] = i;
    }

    int *p2 = (int *)malloc(1 * sizeof(int));
    cout << p2 << endl;

    cout << p << endl;
    p = (int *)realloc(p, 100000000 * sizeof(int));

    if (p != NULL)
    {
        cout << p << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << p[i] << endl;
        }
    }
    else
    {
        cout << "Can't resize";
    }
}