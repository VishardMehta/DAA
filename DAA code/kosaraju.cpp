#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs1(v, adj, visited, st);
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>>& transposed, vector<bool>& visited) {
    visited[u] = true;
    for (int v : transposed[u]) {
        if (!visited[v])
            dfs2(v, transposed, visited);
    }
}

int kosaraju(int V, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(V, false);

    // Step 1: Fill vertices in stack according to their finishing times
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs1(i, adj, visited, st);
    }

    // Step 2: Create transposed graph
    vector<vector<int>> transposed(V);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            transposed[v].push_back(u);
        }
    }

    // Step 3: Process all vertices in order defined by stack
    fill(visited.begin(), visited.end(), false);
    int scc_count = 0;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            dfs2(u, transposed, visited);
            scc_count++;
        }
    }

    return scc_count;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Sample directed graph edges
    vector<pair<int,int>> edges = {
        {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}
    };

    for (auto &e : edges)
        adj[e.first].push_back(e.second);

    int scc = kosaraju(V, adj);
    cout << "Number of Strongly Connected Components: " << scc << "\n";

    return 0;
}
