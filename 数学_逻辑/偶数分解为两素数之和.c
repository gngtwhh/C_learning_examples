#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int check(int x) {
	int k = sqrt(x);
	for (int i = 2; i <= k; ++i)
		if (x % i == 0)
			return 0;
	return 1;
}
int main() {
	int n, i, j, flag = 1;
	scanf("%d", &n);
	for (i = 2;i<=n/2; ++i) {
		if (check(i) && check(n - i)) {
			printf("%d=%d+%d\n", n, i, n - i);
		}
	}
	return 0;
}