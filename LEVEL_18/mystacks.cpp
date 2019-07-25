#include <iostream>

class myStack
{
private:
    int *data_arr = NULL;
    int Capacity = 0;
    int top_of_stack;
    
public:
    myStack(int Capacity)
    {
        data_arr = new int[Capacity];
        this->Capacity = Capacity;
        this->top_of_stack = -1;
    }

};

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
