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
        // int rsb = num - 1; //* these 14 and 15 th lines are alternative to the 12 and 13th line. 14th and 15th are more elegant
        // num = num & (rsb);
        count++;
    }
    cout << count;
}
