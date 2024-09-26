#include <stdio.h>
int main() {
	int f[21] = {0, 1};
	for (int i = 2; i <= 20; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}
	for (int i = 1; i <= 20; ++i) {
		printf("%d ", f[i]);
		if (i % 5 == 0) printf("\n");
	}
	return 0;
}