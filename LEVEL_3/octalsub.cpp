#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int o1, o2;

    cin >> o1 >> o2;
    int c = 0;
    int s = 0;
    int pow = 1;

    while(o1 != 0){
        int r1 = o1 % 10;
        r1 = r1 + c;
        o1 = o1 / 10;

        int r2 = o2 % 10;
        o2 = o2 / 10;
        
        if(r1 < r2)
        {
            r1 += 8;
            c = -1;
        } 
        else 
        {
            c = 0;
        }

        int r = r1 - r2;
        s = s + r * pow;
        pow = pow * 10;
    }

    cout << s;
}








