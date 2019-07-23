#include <iostream>

int main(int argc, char **argv)
{
    myStack ms(5);
    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    ms.push(50);

    while (ms.size() > 0)
    {
        int Value = ms.top();
        ms.pop();
        cout << Value << endl;
    }
    ms.pop();
}
