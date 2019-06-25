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
    
    queue.push(Djikstra_Helper(source, " " + to_string(source), 0));
    
    while (queue.size() > 0)
    {
        Djikstra_Helper remove = queue.top(); //get front
        queue.pop();                          //remove front

        if (visited[remove.vertex] == true)
        {
            continue;
        }
        else
        {
            visited[remove.vertex] = true;
        }
        cout << remove.vertex << " via " << remove.path_so_far << " @ " << remove.distance_so_far << endl;

        for (int neighbour = 0; neighbour < graph[remove.vertex].size(); neighbour++) //add children
        {
            Edge new_edge = graph[remove.vertex][neighbour];
            if (visited[new_edge.neighbour] == false)
            {
                Djikstra_Helper nbr = Djikstra_Helper(new_edge.neighbour, remove.path_so_far + to_string(new_edge.neighbour), remove.distance_so_far + new_edge.weight);
                queue.push(nbr);
            }
        }
     }    
}

class Prims_Helper
{
    public:
    int vertex;
    int acquiring_vertex;
    int cost_of_acquiring;
    
    Prims_Helper(int vertex, int acquiring_vertex, int cost_of_acquiring)
    {
        this->vertex = vertex;
        this->acquiring_vertex = acquiring_vertex;
        this->cost_of_acquiring = cost_of_acquiring;
    }
};

vector<vector<Edge>> Prims(vector<vector<Edge>> &graph, int source)
{
    priority_queue<Prims_Helper, vector<Prims_Helper>, greater<Prims_Helper>> queue;
    vector<bool> visited(graph.size(), false);
    vector<vector<Edge>> subgraph(graph.size());
    
    while (queue.size() > 0)
    {
        Prims_Helper remove = queue.top(); //get front
        queue.pop();                       //remove front

        if (visited[remove.vertex] == true)
        {
            continue;
        }
        else
        {
            visited[remove.vertex] = true;
        }
        
        if (remove.acquiring_vertex != -1)
        {
            addEdge(subgraph, remove.vertex, remove.acquiring_vertex, remove.cost_of_acquiring);
        }
        
        for (int neighbour = 0; neighbour < graph[remove.vertex].size(); neighbour++) //add children
        {
            Edge new_edge = graph[remove.vertex][neighbour]; //new_edge basically means neighbouring_edge
            if (visited[new_edge.neighbour] == false)
            {
                Prims_Helper nbr = Prims_Helper(new_edge.neighbour, remove.vertex, new_edge.weight);
                queue.push(nbr);
            }
        }
    }
    
    return subgraph;   
}

void addEdge(vector<vector<Edge>> &graph, int vertex1, int vertex2, int weight)
{
    graph[vertex1].push_back(Edge(vertex2, weight));
    graph[vertex2].push_back(Edge(vertex1, weight));
}

void display(vector<vector<Edge>> &graph)
{
    for (int vertex = 0; vertex < graph.size(); vertex++)
    {
        cout << vertex << "->";
        for (int neighbour = 0; neighbour < graph[vertex].size(); neighbour++)
        {
            Edge new_edge = graph[vertex][neighbour];
            cout << "[" << new_edge.neighbour << "@" << new_edge.weight << "]";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    vector<vector<Edge>> graph(7);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);
    display(graph);
    cout << endl;
    cout << endl;
    cout << "--------------------Djikstra--------------------" << endl;
    cout << BFS(graph, 0);
    vector<vector<Edge>> subgraph = Prims(graph, 0);
    cout << "\n\n---------------------Prims MST--------------------------" << endl;
    display(subgraph);
}
