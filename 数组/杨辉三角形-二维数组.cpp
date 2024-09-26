#include <stdio.h>
int y[30][30];//全局变量初始值为0
int main()
{
	y[1][1] = 1;
	for (int i = 2; i <= 10; ++i)
		for (int j = 1; j <= i; ++j)
			y[i][j] = y[i - 1][j - 1] + y[i - 1][j];
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= i; ++j)
			printf("%4d ", y[i][j]);
		printf("\n");
	}
}