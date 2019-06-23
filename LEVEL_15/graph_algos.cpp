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
    
    Djikstra_Helper(int vertex, string path_so_far, int distance_so_far)
    {
        this->vertex = vertex;
        this->path_so_far = path_so_far;
        this->distance_so_far = distance_so_far;
    }

    bool operator<(const Djikstra_Helper &other) const
    {
        return this->distance_so_far < other.distance_so_far;
    }

    bool operator>(const Djikstra_Helper &other) const
    {
        return this->distance_so_far > other.distance_so_far;
    }
    
    void display()
    {
        cout << vertex << " " << path_so_far << " " << distance_so_far;
    }
};

bool BFS(vector<vector<Edge>> &graph, int source)
{
    priority_queue<Djikstra_Helper, vector<Djikstra_Helper>, greater<Djikstra_Helper>> queue;
    vector<bool> visited(graph.size(), false);
}
