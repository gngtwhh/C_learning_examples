#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 0)
		printf("偶数");
	else printf("奇数");
	return 0;
}