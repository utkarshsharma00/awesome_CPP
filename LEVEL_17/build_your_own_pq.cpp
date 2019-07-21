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
}
