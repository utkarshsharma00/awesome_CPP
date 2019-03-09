#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int dec = 0;
    int bin = 0;
    cin >> dec;
    int power = 1; //this is basically 10^0
    while (dec != 0)
    {
        int remainder = dec % 2;
        dec = dec / 2;
        bin = bin + remainder * power;
        power = power * 10;
    }
    cout << bin;
} //r