#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int i = 256;

    int *p = &i;
    int **q = &p;

    int j = (int)&i;
    cout << j << endl;
    cout << *(char *)j << endl;
    cout << *(int *)j << endl;

    cout << i << endl;
    cout << &i << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;
    cout << q << endl;
    cout << *q << endl;
    cout << **q << endl;
    cout << *&*&*&*q << endl;
}