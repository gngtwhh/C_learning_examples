#include <stdio.h>
int main() {
	int i, j, flag = 0, sum = 0;
	for (i = 100; i <= 200; ++i) {
		for (j = 2; j < i; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%d ", i);
			sum++;
		}
		flag = 1;
	}
	printf("\nsum=%d", sum);
	return 0;
}