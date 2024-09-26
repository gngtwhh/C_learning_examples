#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
	int x;
	scanf("%d",&x);
	int r_x = 0;
	int k = x;
	while (k != 0)
	{
		r_x = r_x * 10 + k % 10;
		k /= 10;
	}
	if (r_x == x)
	{
		printf("yes");
		getchar();
		getchar();
		return 0;
	}
	printf("no");
	getchar();
	getchar();
}