#include <iostream>
using namespace std;

const int V = 4; // number of vertices

bool is_safe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool solve(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (is_safe(v, graph, color, c)) {
            color[v] = c;
            if (solve(graph, m, color, v + 1))
                return true;
            color[v] = 0; // backtrack
        }
    }
    return false;
}

void print(int color[]) {
    cout << "Solution Exists: Following are the assigned colors:\n";
    for (int i = 0; i < V; i++)
        cout << color[i] << " ";
    cout << endl;
}

void graph_coloring(int graph[V][V], int m) {
    int color[V] = {0};

    if (solve(graph, m, color, 0))
        print(color);
    else
        cout << "Solution does not exist\n";
}

int main() {
    int graph1[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m1 = 3; 
    graph_coloring(graph1, m1); // should succeed

    int graph2[V][V] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    int m2 = 3;
    graph_coloring(graph2, m2); // should fail

    return 0;
}
