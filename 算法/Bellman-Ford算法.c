// Bellman-Ford算法,采用邻接矩阵存图
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int **graph;
    int n, m;
    int start;
} Graph;

void init_graph(Graph *graph) {
    scanf("%d%d", &graph->n, &graph->m);
    scanf("%d", &graph->start);

    graph->graph = (int **)malloc(sizeof(int *) * (graph->n + 1));
    for (int i = 0; i <= graph->n; ++i)
        graph->graph[i] = (int *)malloc(sizeof(int) * (graph->n + 1));

    for (int i = 0; i <= graph->n; ++i) {
        for (int j = 0; j <= graph->n; ++j) {
            graph->graph[i][j] = 0;
        }
    }

    for (int i = 0; i < graph->m; ++i) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w);
        graph->graph[from][to] = w;
    }
}

int* bellman_ford(Graph *graph) {
    int *dis = (int *)malloc(sizeof(int) * (graph->n + 1));

    for (int i = 1; i <= graph->n; ++i)
        dis[i] = 0x7FFFFFFF;

    dis[graph->start] = 0;

    // 最外层循环进行n-1轮松弛操作
    for (int k = 1; k <= graph->n - 1; ++k) {
        for (int i = 1; i <= graph->n; ++i) {
            for (int j = 1; j <= graph->n; ++j) {
                if (graph->graph[i][j] != 0 && dis[j] > dis[i] + graph->graph[i][j]) {
                    dis[j] = dis[i] + graph->graph[i][j];
                }
            }
        }
    }

    return dis;
}

int main() {
    Graph graph;
    init_graph(&graph);
    int *dis = bellman_ford(&graph);

    for (int i = 1; i <= graph.n; ++i) {
        printf("%d ", dis[i]);
    }

    for (int i = 0; i <= graph.n; ++i)
        free(graph.graph[i]);
    free(graph.graph);
    free(dis);

    return 0;
}
