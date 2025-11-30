#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findSet(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findSet(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (rank[a] < rank[b]) swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b]) rank[a]++;
}

int main() {
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 3}, {1, 2, 1},
        {1, 3, 2}, {2, 3, 4}, {3, 4, 2}
    };

    int n = 5;
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

    int cost = 0;
    cout << "Kruskal MST edges:\n";

    for (auto e : edges) {
        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            cost += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Total Cost = " << cost;
    return 0;
}

b)#include <iostream>
#include <limits.h>
using namespace std;

int minKey(int key[], bool mstSet[], int n) {
    int minVal = INT_MAX, idx = 0;
    for (int i = 0; i < n; i++)
        if (!mstSet[i] && key[i] < minVal)
            minVal = key[i], idx = i;
    return idx;
}

int main() {
    int n = 5;
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int parent[5];
    int key[5];
    bool mstSet[5];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Prim MST edges:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << endl;

    return 0;
}

