#include <iostream>
#include <algorithm>
using namespace std;

#define V 6
#define INF 9999

int graph[V][V] = {
    {0, 6, 1, 5, INF, INF},
    {6, 0, 5, INF, 3, INF},
    {1, 5, 0, 5, 6, 4},
    {5, INF, 5, 0, INF, 2},
    {INF, 3, 6, INF, 0, 6},
    {INF, INF, 4, 2, 6, 0}};

void Prim()
{
    int lowcost[V], closest[V];
    bool visited[V] = {false};

    visited[0] = true;
    for (int i = 0; i < V; i++)
    {
        lowcost[i] = graph[0][i];
        closest[i] = 0;
    }

    cout << "Prim MST edges:\n";
    for (int i = 1; i < V; i++)
    {
        int min = INF, k = -1;
        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }

        cout << closest[k] << " - " << k << " : " << min << endl;
        visited[k] = true;

        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && graph[k][j] < lowcost[j])
            {
                lowcost[j] = graph[k][j];
                closest[j] = k;
            }
        }
    }
}


struct Edge
{
    int u, v, w;
};

Edge edges[] = {
    {0, 1, 6}, {0, 2, 1}, {0, 3, 5}, {1, 2, 5}, {1, 4, 3}, {2, 3, 5}, {2, 4, 6}, {2, 5, 4}, {3, 5, 2}, {4, 5, 6}};

int parent[6];

int Find(int x)
{
    if (parent[x] != x)
        parent[x] = Find(parent[x]);
    return parent[x];
}

void Kruskal()
{
    for (int i = 0; i < 6; i++)
        parent[i] = i;

    sort(edges, edges + 10, [](Edge a, Edge b)
         { return a.w < b.w; });

    cout << "Kruskal MST edges:\n";
    for (int i = 0; i < 10; i++)
    {
        int fu = Find(edges[i].u);
        int fv = Find(edges[i].v);
        if (fu != fv)
        {
            cout << edges[i].u << " - " << edges[i].v
                 << " : " << edges[i].w << endl;
            parent[fu] = fv;
        }
    }
}

int main()
{
    Prim();
    Kruskal();
    return 0;
}