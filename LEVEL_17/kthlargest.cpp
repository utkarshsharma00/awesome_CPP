#include <iostream>
#include <queue>

using namespace std;

void kthlargest(int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        if (pq.top() > )
    }

    while (pq.size() > 0)
    {
        int val = pq.top();
        pq.pop();
        cout << val << " ";
    }
}

int main(int argc, char **argv)
{
    kthlargest(4);
}
