#include <stdio.h>
static int num;
void h(int now, short from, short to)
{
	if (now == 1)
	{
		printf("%d %d\n", from, to);
		num++;
		return;
	}
	h(now - 1, from, 6 - from - to);
	printf("%d %d\n", from, to);
	num++;
	h(now - 1, 6 - from - to, to);
}
int main()
{
	int n;
	printf("Please enter the height of Hannott Tower:");
	scanf("%d", &n);
	h(n, 1, 3);
	printf("%d", num);
}