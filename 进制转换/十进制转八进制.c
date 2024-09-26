#include <stdio.h>
int main() {
	int oct = 0, dec, k = 1;
	scanf("%d", &dec);
	while (dec) {
		oct += (dec % 8) * k;
		k*=10;
		dec /= 8;
	}
	printf("%d", oct);
	return 0;
}