#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n, i, flag = 1;
	scanf("%d", &n);
	for (i = 2; i <= n; ++i) {
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%d ", i);
		} else
			flag = 1;
	}
	return 0;
}