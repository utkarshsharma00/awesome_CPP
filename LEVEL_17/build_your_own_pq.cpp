#include <iostream>
#include <vector>
using namespace std;

class Priority_queue
{
private:
    vector<int> list;
    bool type; //true for creating a MinHeap and false for creating a MaxHeap

    bool is_higher_priority(int i, int j)
    {
        if (this->type == true)
        {
            return list[i] < list[j]; //will create a MinHeap
        }

        else
        {
            return list[i] > list[j]; //will create a MaxHeap
        }
    }
    
    void swap(int i, int j)
    {
        int ith = list[i];
        int jth = list[j];
        list[i] = jth;
        list[j] = ith;
    }
    
    void up_heapify(int index)
    {
        int parent_index = (index - 1) / 2;
        if (is_higher_priority(index, parent_index) == true)
        {
            swap(index, parent_index);
            up_heapify(parent_index);
        } 
    }
    
    void down_heapify(int index)
    {
        
    }
    
public:
    Priority_queue(bool type)
    {
        this->type = type;
    }

    void push(int val)
    {
        list.push_back(val);
        up_heapify(list.size() - 1);
    }

    void pop()
    {
        swap(0, list.size() - 1);
        list.pop_back();
        down_heapify(0); 
    }
    
    int top()
    {
        return list[0];        
    }
    
    int size()
    {
        return list.size();
    }

};

int main(int argc, char **argv)
{
    Priority_queue pq(false);

    pq.push(10);
    pq.push(2);
    pq.push(20);
    pq.push(7);
    pq.push(60);
    pq.push(100);
    pq.push(1);
    pq.push(5);
    pq.push(35);
    
    while (pq.size() > 0)
    {
        int val = pq.top();
        pq.pop();
        cout << val << " ";
    }
    cout << endl;
}
