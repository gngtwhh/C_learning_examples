#include <stdio.h>
int main() {
	int i, j, sum = 0;
	for (i = 0; i < 10; ++i) {
		scanf("%d", &j);
		sum = sum + j;
	}
	printf("%d", sum);
	return 0;
}
