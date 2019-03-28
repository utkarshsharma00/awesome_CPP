#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int *p1 = new int;
    int *p2 = new int();
    int *p3 = new int(5);
    int *p = new int[20]; // assigns a block of 5 integers

    for (int i = 0; i < 20; i++)
    {
        cout << *(p + i) << " " << *(i + p) << " " << p[i] << " " << i[p] << endl;
    }
}