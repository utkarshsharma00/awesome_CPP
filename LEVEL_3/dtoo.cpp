#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int dec = 0;
    int oct = 0;
    cin >> dec;
    int power = 1; //this is basically 10^0
    while (dec != 0)
    {
        int remainder = dec % 8;
        dec = dec / 8;
        oct = oct + remainder * power;
        power = power * 10;
    }
    cout << oct;
}
//r