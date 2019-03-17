#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int num;
    cin >> num;

    int count = 0;
    while (num != 0)
    {
        int rsb = (num & (-num)); // or can be done as (num & ((~num)+1)) which is basically 2's complement
        num = num - rsb;
        count++;
    }
    cout << count;
}