#include <iostream>
#include <vector>
using namespace std;

const int V = 5;

bool is_safe(int v, const vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool ham_cycle_util(const vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (pos == V) {

        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (is_safe(v, graph, path, pos)) {
            path[pos] = v;
            if (ham_cycle_util(graph, path, pos + 1))
                return true;
            path[pos] = -1;  // Backtrack
        }
    }
    return false;
}

void ham_cycle(const vector<vector<int>> &graph) {
    vector<int> path(V, -1);
    path[0] = 0; 

    if (ham_cycle_util(graph, path, 1)) {
        cout << "Hamiltonian Cycle exists: ";
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0] << endl; // Return to start vertex
    } else {
        cout << "No Hamiltonian Cycle exists" << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    ham_cycle(graph);

    return 0;
}
