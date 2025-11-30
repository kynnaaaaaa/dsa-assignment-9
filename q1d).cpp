#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minDistance(vector<int>& dist, vector<bool>& visited, int n) {
    int minVal = INT_MAX, idx = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < minVal)
            minVal = dist[i], idx = i;
    return idx;
}

int main() {
    int n = 5;
    int graph[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Dijkstra shortest paths:\n";
    for (int i = 0; i < n; i++)
        cout << "0 -> " << i << " = " << dist[i] << endl;

    return 0;
}
