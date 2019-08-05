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

void addEdge(vector<vector<Edge>> &graph, int v1, int v2, int weight)
{
    graph[v1].push_back(Edge(v2, weight));
    graph[v2].push_back(Edge(v1, weight));
}

int getsize(vector<vector<Edge>> &graph, vector<bool> &visited, int src)
{
    
}

int astro(vector<int> &d1, vector<int> &d2, int vertices)
{
    
}

void display(vector<vector<Edge>> &graph)
{
    cout << "---------------------------" << endl;
    for (int v = 0; v < graph.size(); v++)
    {
        cout << v << "->"
             << " ";
        for (int n = 0; n < graph[v].size(); n++)
        {
            Edge ed = graph[v][n];
            cout << "[" << ed.n << "--" << ed.w << "]";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
}

int main(int argc, char **argv)
{
    vector<int> d1 = {1, 6, 8, 2, 9, 10, 0};
    vector<int> d2 = {2, 9, 3, 5, 5, 3, 11};
    cout << astro(d1, d2, 12);
}
