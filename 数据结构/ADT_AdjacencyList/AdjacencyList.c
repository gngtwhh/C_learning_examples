#include "AdjacencyList.h"
#include <stdio.h>
#include <stdlib.h>

// Create a graph with n vertices and m edges
GraphAdjList *createGraphAdjList(int n, int isWeighted) {
    GraphAdjList *graph = (GraphAdjList *) malloc(sizeof(GraphAdjList));
    graph->vertexNum = n;
    graph->edgeNum = 0;
    graph->isWeighted = isWeighted;
    graph->adjLists = (EdgeNode **) malloc(sizeof(EdgeNode *) * (n + 1));
    for (int i = 0; i <= n; ++i)
        graph->adjLists[i] = NULL;
    return graph;
}

// Destroy a graph
void destroyGraphAdjList(GraphAdjList *graph) {
    for (int i = 1; i <= graph->vertexNum; ++i) {
        EdgeNode *p = graph->adjLists[i];
        while (p != NULL) {
            EdgeNode *q = p;
            p = p->next;
            free(q);
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Add an edge to the graph
void addEdgeAdjList(GraphAdjList *graph, int u, int v, int w) {
    EdgeNode *p = (EdgeNode *) malloc(sizeof(EdgeNode));
    p->dest = v;
    p->weight = graph->isWeighted ? w : 1;
    p->next = graph->adjLists[u];
    graph->adjLists[u] = p;
    ++graph->edgeNum;
}

// Remove an edge from the graph
void removeEdgeAdjList(GraphAdjList *graph, int u, int v) {
    EdgeNode *p = graph->adjLists[u];
    if (p == NULL) return;
    if (p->dest == v) {
        graph->adjLists[u] = p->next;
        free(p);
        --graph->edgeNum;
        return;
    }
    while (p->next != NULL) {
        if (p->next->dest == v) {
            EdgeNode *q = p->next;
            p->next = q->next;
            free(q);
            --graph->edgeNum;
            return;
        }
        p = p->next;
    }
}

// Print the graph
void printGraphAdjList(GraphAdjList *graph){
    printf("Vertex number: %d\n", graph->vertexNum);
    printf("Edge number: %d\n", graph->edgeNum);
    printf("Weighted: %s\n", graph->isWeighted ? "Yes" : "No");
    for (int i = 1; i <= graph->vertexNum; ++i) {
        printf("%d: ", i);
        EdgeNode *p = graph->adjLists[i];
        if(p == NULL) putchar('^');
        while (p != NULL) {
            printf("%d", p->dest);
            if (graph->isWeighted)
                printf("(%d)", p->weight);
            printf(" ");
            p = p->next;
        }
        printf("\n");
    }
}
