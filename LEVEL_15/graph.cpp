#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <climits>
using namespace std;

string minpath;
string maxpath;
string floorpath;
string ceilpath;
int Min = INT_MAX;
int Max = INT_MIN;
int Ceil = INT_MAX;
int Floor = INT_MIN;

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

class Traversal_Helper
{
public:
    int vertex;
    string paths_so_far;
    int distance_so_far;

    Traversal_Helper(int vertex, string paths_so_far, int distance_so_far)
    {
        this->vertex = vertex;
        this->paths_so_far = paths_so_far;
        this->distance_so_far = distance_so_far;
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
    visited[source] = true;
    for (int neighbour = 0; neighbour < graph[source].size(); neighbour++)
    {
        Edge new_edge = graph[source][neighbour];
        if (visited[new_edge.neighbour] == false)
        {

            Ceil_Path(graph, new_edge.neighbour, destination, visited, answer_so_far + to_string(source) + " ", sum + new_edge.weight, data);
        }
    }
    visited[source] = false;
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
    visited[source] = true;
    for (int neighbour = 0; neighbour < graph[source].size(); neighbour++)
    {
        Edge new_edge = graph[source][neighbour];
        if (visited[new_edge.neighbour] == false)
        {
            sum += new_edge.weight;
            floor_Path(graph, new_edge.neighbour, destination, visited, answer_so_far + to_string(source) + " ", sum, data);
            sum -= new_edge.weight;
        }
    }
    visited[source] = false;
}

bool BFS(vector<vector<Edge>> &graph, int source, int destination)
{
    list<Traversal_Helper> queue;
    vector<bool> visited(graph.size(), false);

    queue.push_back(Traversal_Helper(source, to_string(source), 0));
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
    cout << "Max Path\n";
    max_Path(graph, 0, 6, visited, paths_so_far, 0);
    cout << maxpath;
    cout << endl;
    
    cout << "Ceil Path" << endl;
    Ceil_Path(graph, 0, 6, visited, paths_so_far, 0, 30);
    cout << ceilpath << endl;
    cout << "Floor Path" << endl;
    floor_Path(graph, 0, 6, visited, paths_so_far, 0, 60);
    cout << floorpath << endl;
    
    cout << "BFS TRAVERSAL" << endl;
    cout << BFS(graph, 0, 6);
    
}
