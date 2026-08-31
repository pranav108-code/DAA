// Write a program to find the Connected Components of a graph using Depth First Search (DFS).
// CODE BY ALMALE PRANAV CHANDRASHEKHAR
// ROLL NO. 25/DA/009

#include <iostream>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
bool visited[MAX];
int n;

// DFS function
void DFS(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Initialize graph
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;

        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    // Input edges
    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    // Find connected components
    int component = 1;

    cout << "\nConnected Components:\n";

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "Component " << component << ": ";
            DFS(i);
            cout << endl;

            component++;
        }
    }

    return 0;
}
