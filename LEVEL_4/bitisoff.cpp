#include<iostream>
using namespace std;

int main(int argc, char **argv)
{
    int num;
    int k;
    cout << "Enter the num and k\n";
    cin >> num;
    cin >> k;

    int bm = 1 << k;
    if ((num & bm) ==0 )
    {
        cout << "Bit is off\n";
       
    }
    else
    {
        cout << "Bit is on\n";
        num=num^bm; //one more way to do this,see sir's code
        cout<<num;
    }
}