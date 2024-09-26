// 迪杰斯特拉算法-前向星
#include <stdio.h>
#include <stdlib.h>

// #define MAX_EDGE_CNT 50000
// #define MAX_NODE_CNT 10000

typedef struct {
    int to, dis, next;
} Edge;

typedef struct {
    // Edge edge[MAX_EDGE_CNT];
    // int head[MAX_NODE_CNT];
    Edge *edge;
    int *head;
    int cnt;
    int n, m, start; // 单源最短路起点,本代码没有封装一个算法结构体，所以这里直接用graph->start代替
} Graph;

void add_edge(Graph *graph, int from, int to, int w) {
    // 链式前向星
    graph->edge[++graph->cnt].to = to;
    graph->edge[graph->cnt].dis = w;
    graph->edge[graph->cnt].next = graph->head[from];
    graph->head[from] = graph->cnt;
}

void init_graph(Graph *graph) {
    // 输入n,m,start
    scanf("%d%d", &graph->n, &graph->m);
    scanf("%d", &graph->start); // 本代码没有封装一个算法结构体，所以这里直接用graph->start代替

    graph->head = (int *) malloc(sizeof(int) * (graph->n + 1));
    graph->edge = (Edge *) malloc(sizeof(Edge) * (graph->m + 1));

    graph->cnt = 0;
    for (int i = 1; i <= graph->n; i++)
        graph->head[i] = 0;

    // 输入m条边
    for (int i = 0; i < graph->m; ++i) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w);
        add_edge(graph, from, to, w);
    }
}

int *dijkstra(Graph *graph) {
    int start;
    // int vis[MAX_NODE_CNT]; // 访问标记数组
    int *vis = (int *) malloc(sizeof(int) * (graph->n + 1));
    int *dis = (int *) malloc(sizeof(int) * (graph->n + 1));

    // 初始化
    for (int i = 1; i <= graph->n; i++) {
        dis[i] = 0x7FFFFFFF;
        vis[i] = 0;
    }
    // 输入起点
    // scanf("%d", &start);
    start = graph->start; // 本代码没有封装一个算法结构体，所以这里直接用graph->start代替
    dis[start] = 0;

    // 核心代码
    for (int j = 0; j < graph->n; ++j) {
        int min = 0x7FFFFFFF, min_index = -1;
        // 获取当前距起点最近的扩展点
        for (int i = 1; i <= graph->n; ++i) {
            if (dis[i] < min && !vis[i]) {
                min = dis[i];
                min_index = i;
            }
        }
        if (min_index == -1) break;
        vis[min_index] = 1;
        // 更新dis(松弛)
        for (int i = graph->head[min_index]; i != 0; i = graph->edge[i].next) {
            if (dis[graph->edge[i].to] > dis[min_index] + graph->edge[i].dis)
                dis[graph->edge[i].to] = dis[min_index] + graph->edge[i].dis;
        }
    }
    free(vis);
    return dis;
}

int main() {
    Graph graph;
    init_graph(&graph);
    int *dis = NULL;
    dis = dijkstra(&graph);
    for (int i = 1; i <= graph.n; i++)
        printf("%d ", dis[i]);
    free(graph.head);
    free(graph.edge);
    free(dis);
    return 0;
}