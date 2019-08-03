#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
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

void addEdge(vector<vector<Edge>> &graph, int vertex1, int vertex2, int weight)
{
    graph[vertex1].push_back(Edge(vertex2, weight));
    graph[vertex2].push_back(Edge(vertex1, weight));
}

int main(int argc, char **argv)
{
    vector<vector<Edge>> graph(7);
    graph[0].push_back(Edge(1, 1));
    graph[0].push_back(Edge(4, 1));
    graph[1].push_back(Edge(2, 1));
    graph[2].push_back(Edge(3, 1));
    graph[6].push_back(Edge(4, 1));
    graph[6].push_back(Edge(5, 1));
    graph[5].push_back(Edge(3, 1));
    topological_sort(graph);
}


