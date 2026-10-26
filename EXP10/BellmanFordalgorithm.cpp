// Write a program to find the Single Source Shortest Path using the Bellman-Ford algorithm and extend it to detect negative-weight cycles in a weighted directed graph.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (const Edge& edge : edges) {
            if (dist[edge.src] != INT_MAX &&
                dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    // Detect negative-weight cycle
    for (const Edge& edge : edges) {
        if (dist[edge.src] != INT_MAX &&
            dist[edge.src] + edge.weight < dist[edge.dest]) {
            cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    bellmanFord(V, E, edges, source);

    return 0;
}

