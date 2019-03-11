#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int bin = 0;
    int dec = 0;

    cin >> bin;

    int pow = 1; // 8 ^ 0
    while(bin != 0)
    {
        int r = bin % 10;
        bin = bin / 10;
        dec = dec + r * pow;
        pow = pow * 8;
    }

    cout << dec;
}






