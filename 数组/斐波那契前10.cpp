#include <stdio.h>
int main() {
	int f[20] = {0, 1};
	for (int i = 2; i <= 10; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}
	for (int i = 1; i <= 10; ++i) {
		printf("%d ", f[i]);
	}
	return 0;
}