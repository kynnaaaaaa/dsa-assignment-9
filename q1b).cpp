#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v])
            DFSUtil(v, adj, visited);
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    // Simple graph
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(n, false);

    cout << "DFS: ";
    DFSUtil(0, adj, visited);
    return 0;
}
