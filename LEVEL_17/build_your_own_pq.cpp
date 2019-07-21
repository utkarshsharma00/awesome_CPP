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

}
