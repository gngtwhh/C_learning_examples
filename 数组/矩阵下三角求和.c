//求nxn的方阵右下三角形所有元素的和(包括副对角线上的元素)
#include <stdio.h>
int main() {
	int m[100][100], n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &m[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = n - i - 1; j < n; ++j)
			sum += m[i][j];
	printf("sum=%d", sum);
	return 0;
}