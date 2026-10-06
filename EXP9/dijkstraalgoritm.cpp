#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    // Adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;   // Remove this line for a directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    // Distance from source to itself is 0
    dist[source] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < n - 1; count++) {

        int u = -1;

        // Find vertex with minimum distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Display shortest distances
    cout << "\nShortest distances from source vertex " << source << ":\n";

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << " : INF\n";
        else
            cout << "Vertex " << i << " : " << dist[i] << "\n";
    }

    return 0;
}