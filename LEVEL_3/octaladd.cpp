#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int o1, o2;

    cin >> o1 >> o2;
    int c = 0;
    int s = 0;
    int pow = 1;

    while(o1 != 0 || o2 != 0 || c != 0){
        int r1 = o1 % 10;
        o1 = o1 / 10;

        int r2 = o2 % 10;
        o2 = o2 / 10;

        int r = r1 + r2 + c;
        int d = r % 8;
        c = r / 8;

        s = s + d * pow;
        pow = pow * 10;
    }

    cout << s;
}








