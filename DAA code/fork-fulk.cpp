#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

bool dfs(int s, int t, vector<vector<int>>& rGraph, vector<int>& parent, vector<bool>& visited) {
    visited[s] = true;
    if (s == t) return true;

    for (int v = 0; v < (int)rGraph.size(); v++) {
        if (!visited[v] && rGraph[s][v] > 0) {
            parent[v] = s;
            if (dfs(v, t, rGraph, parent, visited))
                return true;
        }
    }
    return false;
}

int ford_fulkerson(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> rGraph = graph; // Residual graph
    vector<int> parent(V, -1);
    int max_flow = 0;

    while (true) {
        vector<bool> visited(V, false);
        if (!dfs(s, t, rGraph, parent, visited))
            break; // No more augmenting path

        // Find minimum residual capacity of the path found by DFS
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities of edges and reverse edges
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    // Graph as adjacency matrix, where graph[u][v] = capacity of edge u->v
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    cout << "Maximum possible flow: " << ford_fulkerson(graph, source, sink) << "\n";

    return 0;
}
