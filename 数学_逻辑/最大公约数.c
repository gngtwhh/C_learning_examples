#include<stdio.h>
int main() {
	int m, n, t,mul;
	scanf("%d%d", &m, &n);
	mul=m*n;
	if (m < n) {
		t = m;
		m = n;
		n = t;
	}
	while (n > 0) {
		t = m % n;
		m = n;
		n = t;
	}
	printf("gcd=%d,lcm=%d", m,mul/m);
	return 0;
}