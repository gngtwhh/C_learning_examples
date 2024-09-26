#include <stdio.h>
#include <math.h>
int getprime(int k) {
	int t = k, sqr, flag = 1;
	while (1) {
		t++;
		sqr = sqrt(t);
		for (int i = 2; i <= sqr; ++i)
			if (t % i == 0) {
				flag = 0;
				break;
			}
		if (flag)
			return t;
		else
			flag = 1;
	}
}
int main() {
	int n, cnt = 0, k = 2;
	scanf("%d", &n);
	printf("%d=", n);
	while (n!=1) {
		while (n % k == 0) {
			n /= k;
			cnt++;
		}
		if(cnt)
			printf("%d^%d+", k, cnt);
		cnt = 0;
		k = getprime(k);
	}
	putchar('\b');
    return 0;
}