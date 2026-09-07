#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX], parent[MAX];
bool ap[MAX];
int V, timeCount = 0;

void DFS(int u)
{
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++timeCount;

    for (int v = 0; v < V; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
            {
                children++;
                parent[v] = u;
                DFS(v);

                if (low[v] < low[u])
                    low[u] = low[v];

                // Root node with more than one child
                if (parent[u] == -1 && children > 1)
                    ap[u] = true;

                // Non-root node
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent[u])
            {
                if (disc[v] < low[u])
                    low[u] = disc[v];
            }
        }
    }
}

int main()
{
    int E, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
        ap[i] = false;

        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(i);
    }

    printf("Articulation Points are:\n");
    for (int i = 0; i < V; i++)
    {
        if (ap[i])
            printf("%d ", i);
    }

    printf("\n");

    return 0;
}
