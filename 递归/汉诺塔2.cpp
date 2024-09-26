#include<stdio.h>
int sum;
static int num[100];
void hanoi(int n, char A, char B, char C) {
	if (n == 0)
		return;
	hanoi(n - 1, A, C, B);//将n-1个盘子由A经过C移动到B
	printf("step %d: move %d from %c->%c\n", sum++, n, A, C);
	num[n]++;
	hanoi(n - 1, B, A, C);//剩下的n-1盘子，由B经过A移动到C
}

int main() {
	int n;
	scanf("%d", &n);
	sum = 1;
	hanoi(n, 'A', 'B', 'C');
	printf("总共%d步\n", sum - 1);
	for (int i = 1; i <= n; ++i) {
		printf("第%d个盘子:%d次\n", i, num[i]);
	}
	return 0;
}