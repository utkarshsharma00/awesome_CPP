#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int x;
    cin >> x;

    for (int bitno = 31; bitno >= 0; bitno--)
    {
        int bitmask = 1 << bitno;
        cout << ((x & bitmask) == 0 ? 0 : 1);
    }
    cout << endl;
}
