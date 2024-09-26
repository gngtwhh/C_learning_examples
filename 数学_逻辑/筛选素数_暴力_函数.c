#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int check(int x) {
	for (int i = 2; i < x; ++i) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 2; i <= n; ++i)
		if (check(i))
			printf("%d ", i);
	return 0;
}