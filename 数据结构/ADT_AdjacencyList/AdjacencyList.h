#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

typedef struct EdgeNode {
    int dest;
    int weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct GraphAdjList {
    int vertexNum;
    int edgeNum;
    int isWeighted; // 0 for unweighted graph, 1 for weighted graph
    EdgeNode **adjLists;
} GraphAdjList;

// Create a graph with n vertices
GraphAdjList *createGraphAdjList(int n, int isWeighted);
// Destroy a graph
void destroyGraphAdjList(GraphAdjList *graph);
// Add an edge to the graph
void addEdgeAdjList(GraphAdjList *graph, int u, int v, int w);
// Remove an edge from the graph
void removeEdgeAdjList(GraphAdjList *graph, int u, int v);
// Print the graph
void printGraphAdjList(GraphAdjList *graph);

#endif //ADJACENCYLIST_H
