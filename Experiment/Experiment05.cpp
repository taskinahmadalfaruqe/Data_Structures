#include <iostream>
#include <queue>
using namespace std;

#define V 10

// Adjacency matrix
int graph[V][V] = {
    {0,1,1,0,0,0,0,0,1,1},
    {1,0,1,1,0,0,0,0,0,0},
    {1,1,0,1,1,0,0,0,0,0},
    {0,1,1,0,1,1,0,0,0,0},
    {0,0,1,1,0,1,1,0,0,0},
    {0,0,0,1,1,0,1,1,0,0},
    {0,0,0,0,1,1,0,1,1,0},
    {0,0,0,0,0,1,1,0,1,1},
    {1,0,0,0,0,0,1,1,0,1},
    {1,0,0,0,0,0,0,1,1,0}
};

bool visited[V];

// DFS traversal
void DFS(int v) {
    cout << v << " ";
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS traversal
void BFS(int start) {
    queue<int> q;
    bool visitedBFS[V] = {false};

    q.push(start);
    visitedBFS[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < V; i++) {
            if (graph[v][i] && !visitedBFS[i]) {
                q.push(i);
                visitedBFS[i] = true;
            }
        }
    }
}

int main() {
    cout << "DFS Traversal: ";
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFS(0);

    cout << "\nBFS Traversal: ";
    BFS(0);

    return 0;
}
