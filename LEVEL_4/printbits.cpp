#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int x;
    cin >> x;

    for (int bn = 31; bn >= 0; bn--) //bn means bitnumber
    {
        int bm = 1 << bn;
        cout << ((x & bm) == 0 ? 0 : 1);
    }
    cout << endl;
}
