#include <stdio.h>
int main()
{
	int n, num[23];
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
		num[i]=0;
	int i, j;
	num[1] = 1;
	for (i = 1; i <= n; ++i) {
		for (j = i; j >= 1; --j) {
			printf("%4d ",num[j]);
			if (j == i)
				num[j+1] = 1;
			num[j] += num[j - 1];
		}
		printf("\n");
	}
	return 0;
}