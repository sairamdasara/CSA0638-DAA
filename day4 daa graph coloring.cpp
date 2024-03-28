#include <stdio.h>
#include <stdbool.h>

#define V 4 

void printSolution(int color[]) {
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

bool isSafe(int graph[V][V], int v, int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0; 
        }
    }

    return false;
}

bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(color);
    return true;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; 
    if (!graphColoring(graph, m)) {
        printf("Solution does not exist\n");
    }

    return 0;
}
