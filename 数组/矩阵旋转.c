//将n*n的矩阵(二维数组)逆时针旋转
#include <stdio.h>
#define N 100
void contrarotate(int (*num)[N],int n) {
	int i, j, temp[N][N];
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			temp[n - j - 1][i] = num[i][j];
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			num[i][j] = temp[i][j];
}
int main() {
	int num[N][N], n;
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			scanf("%d", &num[i][j]);
	contrarotate(num, n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j)
			printf("%3d ", num[i][j]);
		putchar('\n');
	}
	return 0;
}