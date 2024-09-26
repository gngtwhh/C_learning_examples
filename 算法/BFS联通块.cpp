#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int move[4][2] = { 1,0,0,1,-1,0,0,-1 };
char map[1003][1003];
bool flag[1003][1003];
int result[1003][1003];
int front = 0, rear = 0,front2=0,rear2=0, n, m, ans;
int i1, j1;
struct node
{
	int i;
	int j;
};
struct node queue[1000000];
struct node now[1000000];
void push(int i,int j)
{
	//int temp = (rear == n - 1) ? 0 : rear + 1;
	if (front == ((rear == 1000000 - 1) ? 0 : rear + 1)) {
		printf("error:out of memory");
		exit(-1);
	}
	queue[rear].i = i;
	queue[rear].j = j;
	rear = (rear == 1000000 - 1) ? 0 : rear + 1;

	//int temp = (rear == n - 1) ? 0 : rear + 1;
	if (front2 == ((rear2 == 1000000 - 1) ? 0 : rear2 + 1)) {
		printf("error:out of memory");
		exit(-1);
	}
	now[rear2].i = i;
	now[rear2].j = j;
	rear2 = (rear2 == 1000000 - 1) ? 0 : rear2 + 1;
	return;
}
void pop()
{
	front= (front == 1000000 - 1) ? 0 : front + 1;
}
void BFS(int i1, int j1)
{
	ans = 0;
	push(i1, j1);
	flag[i1][j1] = true;
	while (front != rear) {
		struct node temp = queue[front];
		ans++;
		for (int i = 0; i < 4; ++i)
		{
			int nodei = temp.i + move[i][0];
			int nodej = temp.j + move[i][1];
			if (nodei >= 0 && nodei < n && nodej >= 0 && nodej < n)
				if (map[nodei][nodej] != map[temp.i][temp.j]&&!flag[nodei][nodej])
				{
					push(nodei, nodej);
					flag[nodei][nodej] = true;
				}
		}
		front = (front == 1000000 - 1) ? 0 : front + 1;
	}
	//printf("%d\n", ans);
}
int main()
{
	//freopen("in.txt", "r",stdin);
	//freopen("out.txt", "w",stdout);
	//memset(map, '2', sizeof(map));
	scanf("%d%d", &n, &m);
	while (getchar() != '\n');
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (!flag[i][j]) {
				BFS(i, j);
				front = rear = 0;
				while (front2 != rear2) {
					result[now[front2].i][now[front2].j] = ans;
					front2 = (front2 == 1000000 - 1) ? 0 : front2 + 1;
				}
				front2 = rear2 = 0;
			}
		}

	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &i1, &j1);
		printf("%d\n", result[i1 - 1][j1 - 1]);
	}
	return 0;
}