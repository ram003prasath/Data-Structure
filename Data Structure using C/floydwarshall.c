#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

void floydWarshall(int graph[100][100], int V) {
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][k] + graph[k][j] < graph[i][j]) 
				{
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
void printSolution(int dist[100][100], int V) {
    printf("The shortest distances between every pair of vertices are:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];
    printf("Enter the adjacency matrix (INF for infinity):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            char input[10];
            scanf("%s", input);
            if (strcmp(input, "INF") == 0) {
                graph[i][j] = INT_MAX;
            } else {
                graph[i][j] = atoi(input);
            }
        }
    }
    floydWarshall(graph, V);
    printSolution(graph, V);

}