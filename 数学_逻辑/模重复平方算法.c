#include <stdio.h>
int square_and_multiply(int m, int e, int n) {
	int c = 1;
	while (e > 0) {
		if (e & 1)
			c = c * m % n;
		m = m * m % n;
		e >>= 1;
	}
	return c;
}

int main() {
	int m, e, n, c;
	printf("evaluate c=m^e(mod n):\n");
	printf("input m,e,n(<=int): ");
	scanf("%d%d%d", &m, &e, &n);
	c = square_and_multiply(m, e, n);
	printf("%d\n", c);
	return 0;
}