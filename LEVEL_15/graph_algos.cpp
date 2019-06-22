#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

class Edge
{
public:
    int neighbour;
    int weight;

    Edge(int neighbour, int weight)
    {
        this->neighbour = neighbour;
        this->weight = weight;
    }
};

class Djikstra_Helper
{
    public:
    int vertex;
    string path_so_far;
    int distance_so_far;
};
