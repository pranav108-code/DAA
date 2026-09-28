#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an edge
struct Edge {
    int u, v, w;
};

// ---------------- KRUSKAL'S ALGORITHM ----------------

// Find parent of a vertex
int findParent(int parent[], int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent, parent[x]);
}

// Union of two sets
void unionSet(int parent[], int rank[], int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a != b) {
        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

void kruskal(int V, vector<Edge> edges) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;

    cout << "\nKruskal's MST:\n";

    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;

        if (findParent(parent, u) != findParent(parent, v)) {
            cout << u << " - " << v << " : " << edge.w << endl;
            totalWeight += edge.w;

            unionSet(parent, rank, u, v);
        }
    }

    cout << "Total MST Weight = " << totalWeight << endl;
}


// ---------------- PRIM'S ALGORITHM ----------------

void prim(int V, vector<vector<int>> graph) {

    vector<int> key(V, 999999);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        // Find minimum key vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;

    cout << "\nPrim's MST:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        totalWeight += graph[i][parent[i]];
    }

    cout << "Total MST Weight = " << totalWeight << endl;
}


// ---------------- MAIN FUNCTION ----------------

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));
    vector<Edge> edges;

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;

        edges.push_back({u, v, w});
    }

    prim(V, graph);

    kruskal(V, edges);

    return 0;
}