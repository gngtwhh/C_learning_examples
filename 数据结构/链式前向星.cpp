// 链式前向星相比常规前向星(?),无需排序?

//代码修改自SPFA算法代码
#include <iostream>

#define INF 0x7FFFFFFF
using namespace std;
struct EDGE {
	int to, w, next;
};
struct EDGE edge[500003];
int head[100003], n, m, cnt;
void addEdge() {
	int from;
	cin >> from;
	cin >> edge[++cnt].to;
	cin >> edge[cnt].w;
	edge[cnt].next = head[from];
	head[from] = cnt;
}
void init() {
	cout<<"输入点数和边数:"<<endl;
	cin >> n >> m;//n为点数,m为边数
	cout<<"依次输入边(起始 终点 权值):"<<endl;//名称?(?)
	for (int i = 1; i <= m; ++i)
		addEdge();
}
void print() {
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; j; j = edge[j].next) {
			cout<<i<<"--("<<edge[j].w<<")-->"<<edge[j].to<<endl;
		}
	}
	return;
}
int main() {
	init();
	print();
	return 0;
}