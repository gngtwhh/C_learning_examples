#include <stdio.h>
int main() {
	int oct, dec = 0, k = 1;
	scanf("%d", &oct);
	while (oct) {
		dec += (oct % 10) * k;
		k *= 8;
		oct /= 10;
	}
	printf("%d", dec);
	return 0;
}