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
    
    void push(int Value)
    {
       if (top_of_stack == Capacity - 1)
        {
            cout << "Stack Overflow" << endl;
        }

        top_of_stack++;
        data_arr[top_of_stack] = Value; 
    }
    
    void pop()
    {
        if (top_of_stack == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        data_arr[top_of_stack] = 0;
        top_of_stack--;
    }
    
    int top()
    {
        if (top_of_stack == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        
        return data_arr[top_of_stack]; 
    }
    
    int size()
    {
        return top_of_stack + 1;        
    }
    
    bool isEmpty()
    {
        if (top_of_stack == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
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
