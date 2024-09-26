#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void check(int x) {
	int k = sqrt(x);
	for (int i = 2; i <= k; ++i) {
		if (x % i == 0) {
			printf("no");
			exit(0);
		}
	}
	printf("yes");
}
int main() {
	int n;
	scanf("%d", &n);
	check(n);
	return 0;
}