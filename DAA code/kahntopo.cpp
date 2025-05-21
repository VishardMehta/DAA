#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kahn_topo(int V, vector<vector<int>>& adj) {
    vector<int> indeg(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indeg[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    if (topo.size() != V) {
        cout << "Graph has a cycle. No topological ordering possible.\n";
        return;
    }

    for (int x : topo)
        cout << x << " ";
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

    cout << "Kahn's Algorithm Topological Sort:\n";
    kahn_topo(V, adj);

    return 0;
}
