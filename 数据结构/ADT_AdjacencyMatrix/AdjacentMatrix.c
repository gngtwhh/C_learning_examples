#include "AdjacentMatrix.h"
#include <stdio.h>
#include <stdlib.h>

// Create a graph with n vertices and m edges
GraphMatrix *createGraphMatrix(int n, int m, int isWeighted) {
    GraphMatrix *graph = (GraphMatrix *) malloc(sizeof(GraphMatrix));
    graph->vertexNum = n;
    graph->edgeNum = m;
    graph->isWeighted = isWeighted;
    graph->adjacentMatrix = (int **) malloc(sizeof(int *) * (n + 1));
    graph->adjacentMatrix[0] = NULL;
    for (int i = 1; i <= n; ++i) {
        graph->adjacentMatrix[i] = (int *) malloc(sizeof(int) * (n + 1));
        for (int j = 1; j <= n; ++j)
            graph->adjacentMatrix[i][j] = 0;
    }

    return graph;
}

// Destroy a graph
void destroyGraphMatrix(GraphMatrix *graph) {
    for (int i = 1; i <= graph->vertexNum; ++i)
        free(graph->adjacentMatrix[i]);
    free(graph->adjacentMatrix);
    free(graph);
}

// Add an edge to the graph
void addEdgeMatrix(GraphMatrix *graph, int u, int v, int w) {
    // 检查是否为带权图

    graph->adjacentMatrix[u][v] = graph->isWeighted ? w : 1;
}

// Remove an edge from the graph
void removeEdgeMatrix(GraphMatrix *graph, int u, int v) {
    graph->adjacentMatrix[u][v] = 0;
}

// Print the graph
void printGraphMatrix(GraphMatrix *graph) {
    for (int i = 1; i <= graph->vertexNum; ++i) {
        for (int j = 1; j <= graph->vertexNum; ++j)
            printf("%d ", graph->adjacentMatrix[i][j]);
        printf("\n");
    }
}
