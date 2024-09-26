#include <stdio.h>
int main() {
	int oct = 0, dec, k = 1;
	scanf("%d", &dec);
	while (dec) {
		oct += (dec % 2) * k;
		k*=10;
		dec /= 2;
	}
	printf("%d", oct);
	return 0;
}