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
    visited[source] = true;
    for (int neighbour = 0; neighbour < graph[source].size(); neighbour++)
    {
        Edge new_edge = graph[source][neighbour];
        if (visited[new_edge.neighbour] == false)
        {
            if (hasPath(graph, new_edge.neighbour, destination, visited) == true)
            {
                return true;
            }
        }
    }

    return false;
}

void allPaths(vector<vector<Edge>> &graph, int source, int destination, vector<bool> &visited, string answer_so_far)
{
    if (source == destination)
    {
        cout << answer_so_far << destination << endl;
        return;
    }
    visited[source] = true;
    for (int neighbour = 0; neighbour < graph[source].size(); neighbour++)
    {
        Edge new_edge = graph[source][neighbour];
        if (visited[new_edge.neighbour] == false)
        {
            allPaths(graph, new_edge.neighbour, destination, visited, answer_so_far + to_string(source));
        }
    }
    visited[source] = false;
}

void min_Path(vector<vector<Edge>> &graph, int source, int destination, vector<bool> &visited, string answer_so_far, int sum)
{
    if (source == destination)
    {
        if (sum < Min)
        {
            Min = sum;
            minpath = answer_so_far + to_string(destination);
        }
        return;
    }
    visited[source] = true;
    for (int neighbour = 0; neighbour < graph[source].size(); neighbour++)
    {
        Edge new_edge = graph[source][neighbour];
        if (visited[new_edge.neighbour] == false)
        {
            sum += new_edge.weight;
            min_Path(graph, new_edge.neighbour, destination, visited, answer_so_far + to_string(source) + " ", sum);
        }
    }
    visited[source] = false;
}

void max_Path(vector<vector<Edge>> &graph, int source, int destination, vector<bool> &visited, string answer_so_far, int sum)
{
    if (source == destination)
    {
        if (Max < sum)
        {
            Max = sum;
            maxpath = answer_so_far + to_string(destination);
        }
        return;
    }
    visited[source] = true;
    for (int neighbour = 0; neighbour < graph[source].size(); neighbour++)
    {
        Edge new_edge = graph[source][neighbour];
        if (visited[new_edge.neighbour] == false)
        {
            sum += new_edge.weight;
            max_Path(graph, new_edge.neighbour, destination, visited, answer_so_far + to_string(source) + " ", sum);
        }
    }
    visited[source] = false;
}

void Ceil_Path(vector<vector<Edge>> &graph, int source, int destination, vector<bool> &visited, string answer_so_far, int sum, int data)
{
    if (source == destination)
    {
        if (sum > data && Ceil > sum)
        {
            Ceil = sum;
            ceilpath = answer_so_far + to_string(destination);
        }
        return;
    }
}

void floor_Path(vector<vector<Edge>> &graph, int source, int destination, vector<bool> &visited, string answer_so_far, int sum, int data)
{
    if (source == destination)
    {
        if (sum < data && Floor < sum)
        {
            Floor = sum;
            floorpath = answer_so_far + to_string(destination);
        }
        return;
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
    
    vector<bool> visited(graph.size(), 0); //*Required for all other functions
    cout << "Has Path?" << endl;
    cout << hasPath(graph, 0, 5, visited);
    cout << "\nAll Paths" << endl;
    string paths_so_far = " ";
    allPaths(graph, 0, 6, visited, paths_so_far);
    cout << endl;
    cout << "Min Path\n";
    min_Path(graph, 0, 6, visited, paths_so_far, 0);
    cout << minpath;
    cout << endl;
}
