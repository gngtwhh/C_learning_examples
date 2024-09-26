//洛谷P3371
//该题为弱化版数据,P4779为标准版,标准版的数据卡SPFA
#include <iostream>
#include <queue>
#include <map>
#define INF 0x7FFFFFFF
using namespace std;
struct EDGE {
	int to, w, next;
};
struct EDGE edge[500003];
int head[100003], dis[100003], n, m, s,cnt;
int vis[100003];
void addEdge() {
	int from;
	cin >> from;
	cin >> edge[++cnt].to;
	cin >> edge[cnt].w;
	edge[cnt].next = head[from];
	head[from] = cnt;
}
//typedef pair<int, int> p;
queue<int> q;
void init() {
	cin >> n >> m >> s;
	for (int i = 1; i <= m; ++i)
		addEdge();
	for (int i = 1; i <= n; ++i)
		dis[i] = INF;
}
void SPFA() {
	q.push(s);
	dis[s] = 0;
	vis[s]++;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		if (vis[node] >= n)
			break;//有环
		for (int i = head[node]; i; i = edge[i].next) {
			if (dis[edge[i].to] > dis[node] + edge[i].w) {
				dis[edge[i].to] = dis[node] + edge[i].w;
				q.push(edge[i].to);
				vis[edge[i].to]++;
			}
		}
	}
}
void print() {
	for (int i = 1; i <= n; ++i)
		cout << dis[i] << ' ';
}
int main() {
	init();
	SPFA();
	print();
	return 0;
}