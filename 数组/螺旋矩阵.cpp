//网友期望的一个程序...
//从中心旋转---经简单修改可以转换为一般的螺旋矩阵
//关键为move数组
#include <stdio.h>
#include <math.h>
#define N 103
int main()
{
	int n,sqrt_n,n2, num[N][N] = { 0 }, x, y, m = 0;
	int move[4][2] = {
		0,-1,1,0,0,1,-1,0
	};
	while (scanf("%d", &n)) {
		if (sqrt(n)*sqrt(n) == n)
			break;
		printf("请输入完全平方数!\n");
	}
	sqrt_n = sqrt(n);
	x = 1, y = sqrt_n;
	while (n) {
		num[x][y] = n--;
		int x1, y1;
		x1 = x + move[m][0];
		y1 = y + move[m][1];
		if (x1 >= 1 && x1 <= sqrt_n && y1 >= 1 && y1 <= sqrt_n && num[x1][y1] == 0) {
			x = x1;
			y = y1;
		}
		else {
			m = (m + 1 == 4 ? 0 : m + 1);
			x += move[m][0];
			y += move[m][1];
		}
	}
	for (int i = 1; i <= sqrt_n; ++i) {
		for (int j = 1; j <= sqrt_n; ++j) {
			printf("%3d ", num[i][j]);
		}
		printf("\n");
	}
	return 0;
}
