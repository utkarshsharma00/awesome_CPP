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

class Kruskal_Helper
{
    public:
    int vertex_1;
    int vertex_2;
    int weight;
    
    Kruskal_Helper(int vertex_1, int vertex_2, int weight)
    {
        this->vertex_1 = vertex_1;
        this->vertex_2 = vertex_2;
        this->weight = weight;
    }
    
    bool operator>(const Kruskal_Helper &other) const
    {
        return this->weight > other.weight;
    }
};

void Merge(vector<int> &pointer_array, vector<int> &rank_array, int vertex_1_set_leader, int vertex_2_set_leader) //required for Kruskal's
{
    if (rank_array[vertex_1_set_leader] < rank_array[vertex_2_set_leader])
    {
        pointer_array[vertex_1_set_leader] = vertex_2_set_leader;
    }
    
    else if (rank_array[vertex_2_set_leader] < rank_array[vertex_1_set_leader])
    {
        pointer_array[vertex_2_set_leader] = vertex_1_set_leader;
    }
    
    else
    {
        pointer_array[vertex_1_set_leader] = vertex_2_set_leader;
        rank_array[vertex_2_set_leader]++;
    }
}

int find(vector<int> &pointer_array, int vertex) //required for Kruskal's
{
    if (pointer_array[vertex] == vertex)
    {
        return vertex;
    }
    
    else
    {
        int set_leader = find(pointer_array, pointer_array[vertex]);
        return set_leader;
    }
}

vector<vector<Edge>> Kruskals(vector<vector<Edge>> &graph)
{
    vector<vector<Edge>> minimum_spanning_tree(graph.size());
    vector<int> pointer_array(graph.size());
    vector<int> rank_array(graph.size());
    
    for (int i = 0; i < pointer_array.size(); i++)
    {
        pointer_array[i] = i;
    }
    
    priority_queue<Kruskal_Helper, vector<Kruskal_Helper>, greater<Kruskal_Helper>> queue;
    
    for (int vertex = 0; vertex < graph.size(); vertex++)
    {
        for (int neighbour = 0; neighbour < graph[vertex].size(); neighbour++)
        {
            Edge new_edge = graph[vertex][neighbour];
            if (vertex < new_edge.neighbour)
            {
                Kruskal_Helper KE(vertex, new_edge.neighbour, new_edge.weight);
                queue.push(KE);
            }
        }
    }
    
    int counter = 0;
    while (queue.size() > 0 && counter < graph.size() - 1)
    {
        Kruskal_Helper KE = queue.top();
        queue.pop();

        int v1_set_leader = find(pointer_array, KE.vertex_1);
        int v2_set_leader = find(pointer_array, KE.vertex_2);

        if (v1_set_leader < v2_set_leader)
        {
            addEdge(minimum_spanning_tree, KE.vertex_1, KE.vertex_2, KE.weight);
            Merge(pointer_array, rank_array, v1_set_leader, v2_set_leader);
            counter++;
        }
    }

    return minimum_spanning_tree;
}

class Bellman_Helper
{
    public:
    int vertex_1;
    int vertex_2;
    int weight;

    Bellman_Helper(int vertex_1, int vertex_2, int weight)
    {
        this->vertex_1 = vertex_1;
        this->vertex_2 = vertex_2;
        this->weight = weight;
    }
    
    bool operator>(const Bellman_Helper &other) const
    {
        return this->weight > other.weight;
    }
};

void bellman(vector<vector<Edge>> &graph, int source)
{
    vector<int> result(graph.size(), INT_MAX);
    vector<Bellman_Helper> all_edges;
    
    result[source] = 0;

    for (int vertex = 0; vertex < graph.size(); vertex++)
    {
        for (int neighbour = 0; neighbour < graph[vertex].size(); neighbour++)
        {
            Edge new_edge = graph[vertex][neighbour];
            Bellman_Helper BE(vertex, new_edge.neighbour, new_edge.weight);
            all_edges.push_back(BE);
        }
    }
    
    for (int i = 0; i < graph.size() - 1; i++)
    {
        for (int j = 0; j < all_edges.size(); j++)
        {
            Bellman_Helper BE = all_edges[j];
            if (result[BE.vertex_1] != INT_MAX)
            {
                if (result[BE.vertex_1] + BE.weight < result[BE.vertex_2])
                {
                    result[BE.vertex_2] = result[BE.vertex_1] + BE.weight;
                }
            }
        }
    }
    
    for (int j = 0; j < all_edges.size(); j++)
    {
        Bellman_Helper BE = all_edges[j];
        if (result[BE.vertex_1] != INT_MAX)
        {
            if (result[BE.vertex_1] + BE.weight < result[BE.vertex_2])
            {
                cout << "Negative Cycle\n";
                return;
            }
        }
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

void floyd_warshall(vector<vector<Edge>> &graph) //TODO See comments in the notebook for this specific code
{
    vector<vector<int>> result = {graph.size(), vector<int>(graph.size(), INT_MAX)};

    for (int i = 0; i < graph.size(); i++)
    {
        result[i][i] = 0;
        for (int neighbour = 0; neighbour < graph[i].size(); neighbour++)
        {
            Edge new_edge = graph[i][neighbour];
            result[i][new_edge.neighbour] = new_edge.weight;
        }
    }
    
    for (int intermediate = 0; intermediate < graph.size(); intermediate++)
    {
        for (int source = 0; source < graph.size(); source++)
        {
            for (int destination = 0; destination < graph.size(); destination++)
            {
            }
        }
    }
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
    
    vector<vector<Edge>> subgraph_via_Kruskals = Kruskals(graph);
    cout << "\n\n----------------Kruskal's MST-------------" << endl;
    display(subgraph_via_Kruskals);
    cout << endl;
    cout << "\n\n----------------Floyd Warshall-------------" << endl;
    vector<vector<Edge>> floyd_warshall_graph(4);
    floyd_warshall_graph[0].push_back(Edge(1, 2));
    floyd_warshall_graph[0].push_back(Edge(3, 8));
    floyd_warshall_graph[0].push_back(Edge(2, 4));
    floyd_warshall_graph[1].push_back(Edge(2, 1));
    floyd_warshall_graph[1].push_back(Edge(3, 5));
    floyd_warshall_graph[2].push_back(Edge(3, 1));
    floyd_warshall(floyd_warshall_graph);
    cout << endl;
    cout << "Bellman Ford\n";
    bellman(floyd_warshall_graph, 0);
}
