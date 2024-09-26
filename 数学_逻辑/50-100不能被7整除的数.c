#include <stdio.h>
int main() {
	int i;
	for (int i = 50; i <= 100; ++i) {
		if (i % 7 != 0) {
			printf("%d ", i);
		}
	}
	return 0;
}