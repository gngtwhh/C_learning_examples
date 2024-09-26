// 判别a是否为模p(p为素数)的平方剩余
#include <stdio.h>
#include <math.h>
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
int Euler(int a, int p) {
	int ex = square_and_multiply(a, (p - 1) / 2, p);
	if (ex > 1) ex -= p; //非1的情况转为-1
	return (ex + 1) / 2; //1和-1分别映射为1和0
}
int isprime(int x) {
	int k = sqrt(x);
	for (int i = 2; i <= k; ++i)
		if (x % i == 0)
			return 0;
	return 1;
}
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
int main() {
	int a, p;
	printf("input a,p((a,p)=1): ");
	scanf("%d%d", &a, &p);
	if (!isprime(p)) {
		printf("error:p is not prime!\n");
		return 0;
	}
	if (gcd(a, p) != 1) {
		printf("error:not coprime!\n"); //?
		return 0;
	}
	if (Euler(a, p))
		printf("yes\n");
	else printf("no\n");
	return 0;
}