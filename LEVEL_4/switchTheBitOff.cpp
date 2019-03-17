#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    int b;

    cin >> n;
    cin >> b;

    int bm = 1 << b;
    if ((n & bm) == 0)
    {
        cout << "Bit is off" << endl;
    }
    else
    {
        cout << "Bit is on" << endl;
        int nbm = ~bm;
        n = n & nbm;
        cout << n;
    }
}
