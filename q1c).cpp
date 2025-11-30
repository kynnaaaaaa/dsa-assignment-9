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
