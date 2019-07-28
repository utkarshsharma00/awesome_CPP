#include <queue>
#include <iostream>
using namespace std;

class Helper
{
public:
    int list_index;
    int data_index;
    int value;
    
    Helper(int list_index, int data_index, int value)
    {
        this->list_index = list_index;
        this->data_index = data_index;
        this->value = value;
    }

    bool operator<(const Helper &other) const
    {
        return this->value > other.value; //smartness here in comparisons
    }
};

void mergeKsortedLists(vector<vector<int>> &lists)
{
    priority_queue<Helper> pq;
}

int main(int argc, char **argv)
{
    vector<vector<int>> lists{{2, 5, 9, 18, 20, 25},
                              {3, 7, 8, 15, 22},
                              {0, 4, 6, 12},
                              {1, 10, 16, 21, 28}};
    mergeKsortedLists(lists);
}
