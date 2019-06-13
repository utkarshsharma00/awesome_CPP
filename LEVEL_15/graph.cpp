#include <iostream>
#include <vector>
#include <string>
#include <list>
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

void addEdge(vector<vector<Edge>> &graph, int vertex1, int vertex2, int weight)
{
    graph[vertex1].push_back(Edge(vertex2, weight));
    graph[vertex2].push_back(Edge(vertex1, weight));
}

bool hasPath(vector<vector<Edge>> &graph, int source, int destination, vector<bool> &visited)
{
    if (source == destination)
    {
        return true;
    }
}

int main(int argc, char **argv)
{
    vector<vector<Edge>> graph(9);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);
    addEdge(graph, 7, 0, 2);
    addEdge(graph, 7, 8, 2);
    addEdge(graph, 8, 0, 2);
}
