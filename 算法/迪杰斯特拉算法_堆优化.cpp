//洛谷P3371
//见 https://blog.csdn.net/CSDNjiangshan/article/details/79345031
//该程序为堆优化写法(另见朴素写法)
//=================
//另外见 https://www.jianshu.com/p/688181720979/
//该博客中一个重要的解释:
//优先队列不提供修改队内某元素优先级的的操作，
//因此在得到某结点x的更小的dist后，更新dist[x]，
//再直接再入队一个pair (new_dist,x) 就好。
//因为new_dist比队列中结点x原先的dist要小，必定比原先那个“过时”的元素先出队
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#define INF 0x7FFFFFFF
using namespace std;
int cnt, n, m, s, head[100003], dis[100003];
bool vis[100003];//标记数组
struct EDGE {
	int to, dis, next;
} edge[500003]; //head和edge-->链式前向星
typedef pair<int, int> p;//first为路径长度,second为点
priority_queue<p, vector<p>, greater<p> > q;//优先队列,从小到大---堆优化
//每当搜索到一个新点，扔到优先队列里面，这样每次就取队首的绝对是最优值--
//-->省去内层循环
// 这里的堆根据pair的first来排序，所以每次取出的都是最小的first
void add_edge() {
	int from;
	cin >> from;
	cin >> edge[++cnt].to;//从1开始
	cin >> edge[cnt].dis;
	edge[cnt].next = head[from];//最初的0等同于NULL
	head[from] = cnt;//from结点最新读取的一条出边作为遍历时访问的第一条边
}
void init() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i)
		add_edge();
	for (int i = 1; i <= n; ++i) dis[i] = INF;
}
void dijkstra() {
	dis[s] = 0;
	q.push(p(0, s));
	while (!q.empty()) {
		p node = q.top(); q.pop();
		int v = node.second;
		if (vis[v])continue;
		vis[v] = true;
		for (int i = head[v]; i; i = edge[i].next) { //终止条件为i==0即等同于NULL
			if (dis[edge[i].to] > edge[i].dis + node.first) {
				//node.first也可写为dis[v](?)
				dis[edge[i].to] = edge[i].dis + node.first;
				q.push(p(dis[edge[i].to], edge[i].to));
			}
		}
	}
}
void print() {
	for (int i = 1; i <= n; ++i)
		cout << dis[i] << " ";
}
int main() {
	init();
	dijkstra();
	print();
	return 0;
}