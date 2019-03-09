#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int dec = 0;
    int bin = 0;
    cin >> bin;
    int power = 1; //this is basically 2^0
    while (bin != 0)
    {
        int remainder = bin % 10;
        bin = bin / 10;
        dec = dec + remainder * power;
        power = power * 2;
    }
    cout << dec;
}
//r