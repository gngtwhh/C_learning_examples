#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int ratosthenes(int prime[], int n)
{
	bool* flag = (bool*)malloc(sizeof(bool) * (n / 2 + 1));
	int temp,j, len = 0;
	memset(flag, true, sizeof(bool) * (n / 2 + 1));
	prime[len++] = 2;
	for (int i = 2; i*2-1 <= n; ++i)
	{
		if (!flag[i]) continue;
		j = temp = i * 2 - 1;
		while (temp <= n)
		{
			flag[(temp + 1) / 2] = false;
			temp += j*2;
		}
		prime[len++] = i*2-1;
	}
	return len;
}
int main()
{
	int* prime = NULL, n, len;
	scanf("%d", &n);
	prime = (int*)malloc(sizeof(int) * (n / 2));
	memset(prime, 0, sizeof(int) * (n / 2));
	len = ratosthenes(prime, n);
	for (int i = 0; i < len; ++i)
		printf("%6d\t", prime[i]);
	printf("\n==========\ntotal %d", len);
	return 0;
}
