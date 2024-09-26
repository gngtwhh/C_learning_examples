#include <stdio.h>
int main() {
	int sum = 0;
	for (int i = 1000; i <= 9999; ++i) {
		int temp = i, rev = 0;
		while (temp) {
			rev = rev * 10 + temp % 10;
			temp /= 10;
		}
		if (rev == i) {
			printf("%d ",i);
			sum += i;
		}
	}
	printf("\n%d", sum);
	return 0;
}