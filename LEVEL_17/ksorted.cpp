#include <iostream>
#include <queue>
using namespace std;

void ksorted(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }
}

int main(int argc, char **argv)
{
    vector<int> arr{20, 40, 10, 30, 50, 80, 60, 90, 70, 120, 110, 100};
    ksorted(arr, 2);
}
