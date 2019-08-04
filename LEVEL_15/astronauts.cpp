#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <list>

using namespace std;
class Edge
{
public:
    int n; //neighbour
    int w; //weight
    Edge(int n, int w)
    {
        this->n = n;
        this->w = w;
    }
};

int main(int argc, char **argv)
{
    vector<int> d1 = {1, 6, 8, 2, 9, 10, 0};
    vector<int> d2 = {2, 9, 3, 5, 5, 3, 11};
    cout << astro(d1, d2, 12);
}
