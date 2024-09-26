//
// Created by WAHAHA on 2023/12/30.
//

#include <stdio.h>
#include "AdjacencyList.h"

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    GraphAdjList *graph = createGraphAdjList(n, 1);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdgeAdjList(graph, u, v, w);
    }
    printGraphAdjList(graph);
    destroyGraphAdjList(graph);
    return 0;
}
