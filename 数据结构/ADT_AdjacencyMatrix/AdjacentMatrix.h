#ifndef ADJACENTMATRIXH
#define ADJACENTMATRIXH

typedef struct GraphMatrix {
    int vertexNum;
    int edgeNum;
    int isWeighted; // 0 for unweighted graph, 1 for weighted graph
    int **adjacentMatrix;
} GraphMatrix;

// Create a graph with n vertices and m edges
GraphMatrix *createGraphMatrix(int n, int m,int isWeighted);
// Destroy a graph
void destroyGraphMatrix(GraphMatrix *graph);
// Add an edge to the graph
void addEdgeMatrix(GraphMatrix *graph, int u, int v, int w);
// Remove an edge from the graph
void removeEdgeMatrix(GraphMatrix *graph, int u, int v);
// Print the graph
void printGraphMatrix(GraphMatrix *graph);

#endif //ADJACENTMATRIXH
