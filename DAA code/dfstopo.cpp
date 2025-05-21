#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& topo) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v, adj, visited, topo);
    }
    topo.push_back(u);
}

void dfs_topo(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<int> topo;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, adj, visited, topo);
    }

    // topo currently has reverse topological order
    for (int i = V - 1; i >= 0; i--) {
        cout << topo[i] << " ";
    }
    cout << "\n";
}


int main() {
    int V = 6;
    vector<vector<int>> edges = {
        {2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}
    };

    vector<vector<int>> adj(V);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
    }

    cout << "DFS Based Topological Sort:\n";
    dfs_topo(V, adj);

    return 0;
}
