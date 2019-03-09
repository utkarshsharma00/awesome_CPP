#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int oct = 0;
    int bin = 0;
    cin >> bin;
    int power = 1;

    while (bin != 0)
    {
        int remainder = bin % 1000;
        bin = bin / 1000;

        switch (remainder)
        {
        case 0:
            remainder = 0;
            break;
        case 1:
            remainder = 1;
            break;
        case 10:
            remainder = 2;
            break;
        case 11:
            remainder = 3;
            break;
        case 100:
            remainder = 4;
            break;
        case 101:
            remainder = 5;
            break;
        case 110:
            remainder = 6;
            break;
        case 111:
            remainder = 7;
            break;
        default:
            return 1;
        }
        oct = oct + remainder * power;
        power = power * 10;
    }
    cout << oct;
}
//r